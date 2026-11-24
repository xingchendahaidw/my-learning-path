#include <cstddef>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

template<class Key, class T,
         class Hash = std::hash<Key>,
         class KeyEqual = std::equal_to<Key>>
class HashMap {
public:
    using key_type        = Key;
    using mapped_type     = T;
    using value_type      = std::pair<const Key, T>;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using hasher          = Hash;
    using key_equal       = KeyEqual;
    using reference       = value_type&;
    using const_reference = const value_type&;

private:
    /* -------- 节点：每个桶挂一条单链表 -------- */
    struct Node {
        value_type kv;        // first 是 const Key，保证 key 不可被外部改动
        Node*      next;

        template<class K, class... Args>
        Node(K&& k, Args&&... args)
            : kv(std::piecewise_construct,
                 std::forward_as_tuple(std::forward<K>(k)),
                 std::forward_as_tuple(std::forward<Args>(args)...)),
              next(nullptr) {}
    };

    /* -------- 前向迭代器 -------- */
    template<bool IsConst>
    class basic_iterator {
        template<bool> friend class basic_iterator;
        friend class HashMap;

        using map_ptr  = std::conditional_t<IsConst, const HashMap*, HashMap*>;
        using node_ptr = std::conditional_t<IsConst, const Node*, Node*>;

        map_ptr     map_    = nullptr;
        std::size_t bucket_ = 0;
        node_ptr    node_   = nullptr;

        basic_iterator(map_ptr m, std::size_t b, node_ptr n)
            : map_(m), bucket_(b), node_(n) {}

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = typename HashMap::value_type;
        using difference_type   = std::ptrdiff_t;
        using reference         = std::conditional_t<IsConst, const value_type&, value_type&>;
        using pointer           = std::conditional_t<IsConst, const value_type*, value_type*>;

        basic_iterator() = default;

        // iterator -> const_iterator 的隐式转换
        template<bool C = IsConst, class = std::enable_if_t<C>>
        basic_iterator(const basic_iterator<false>& o)
            : map_(o.map_), bucket_(o.bucket_), node_(o.node_) {}

        reference operator*()  const { return node_->kv; }
        pointer   operator->() const { return std::addressof(node_->kv); }

        basic_iterator& operator++() {
            node_ = node_->next;
            while (!node_) {                       // 当前链走完，跳到下一个非空桶
                ++bucket_;
                if (bucket_ >= map_->buckets_.size()) break;
                node_ = map_->buckets_[bucket_];
            }
            return *this;
        }
        basic_iterator operator++(int) { auto t = *this; ++*this; return t; }

        friend bool operator==(const basic_iterator& a, const basic_iterator& b) {
            return a.map_ == b.map_ && a.node_ == b.node_;
        }
        friend bool operator!=(const basic_iterator& a, const basic_iterator& b) {
            return !(a == b);
        }
    };

    /* -------- 数据成员 -------- */
    std::vector<Node*> buckets_;
    std::size_t        size_ = 0;
    hasher             hash_{};
    key_equal          eq_{};

    static constexpr std::size_t kInitialCapacity = 8;
    static constexpr double      kMaxLoadFactor   = 0.75;

    std::size_t bucket_index(const Key& key, std::size_t cap) const {
        return static_cast<std::size_t>(hash_(key)) % cap;
    }

    void rehash_impl(std::size_t newcap) {
        std::vector<Node*> nb(newcap, nullptr);
        for (Node* head : buckets_) {
            Node* n = head;
            while (n) {
                Node* next = n->next;            // 先保存，因为要改 n->next
                std::size_t idx = bucket_index(n->kv.first, newcap);
                n->next = nb[idx];               // 头插到新桶
                nb[idx] = n;
                n = next;
            }
        }
        buckets_.swap(nb);
    }

    void clear_nodes() noexcept {
        for (Node*& head : buckets_) {
            Node* n = head;
            while (n) { Node* next = n->next; delete n; n = next; }
            head = nullptr;
        }
        size_ = 0;
    }

    void copy_from(const HashMap& o) {
        buckets_.assign(o.buckets_.size(), nullptr);
        size_ = 0;
        for (Node* head : o.buckets_)
            for (Node* n = head; n; n = n->next)
                emplace(n->kv.first, n->kv.second);
    }

public:
    using iterator       = basic_iterator<false>;
    using const_iterator = basic_iterator<true>;

    /* ---------------- 构造 / 析构 ---------------- */
    HashMap() : buckets_(kInitialCapacity, nullptr) {}
    explicit HashMap(size_type n) : buckets_(n ? n : kInitialCapacity, nullptr) {}

    HashMap(std::initializer_list<value_type> il)
        : buckets_(kInitialCapacity, nullptr) {
        for (const auto& v : il) insert(v);
    }

    HashMap(const HashMap& o) : hash_(o.hash_), eq_(o.eq_) { copy_from(o); }

    HashMap(HashMap&& o) noexcept(
        std::is_nothrow_move_constructible_v<hasher> &&
        std::is_nothrow_move_constructible_v<key_equal>)
        : buckets_(std::move(o.buckets_)), size_(o.size_),
          hash_(std::move(o.hash_)), eq_(std::move(o.eq_)) {
        o.buckets_.clear();
        o.size_ = 0;
    }

    HashMap& operator=(const HashMap& o) {
        if (this != &o) { HashMap tmp(o); swap(tmp); }   // copy-and-swap
        return *this;
    }

    HashMap& operator=(HashMap&& o) noexcept(
        std::is_nothrow_move_assignable_v<hasher> &&
        std::is_nothrow_move_assignable_v<key_equal>) {
        if (this != &o) {
            clear_nodes();
            buckets_ = std::move(o.buckets_);
            size_    = o.size_;
            hash_    = std::move(o.hash_);
            eq_      = std::move(o.eq_);
            o.buckets_.clear();
            o.size_ = 0;
        }
        return *this;
    }

    ~HashMap() { clear_nodes(); }

    void swap(HashMap& o) noexcept {
        buckets_.swap(o.buckets_);
        std::swap(size_, o.size_);
        std::swap(hash_, o.hash_);
        std::swap(eq_,   o.eq_);
    }

    /* ---------------- 容量 ---------------- */
    bool empty() const noexcept { return size_ == 0; }
    size_type size() const noexcept { return size_; }
    size_type bucket_count() const noexcept { return buckets_.size(); }

    double load_factor() const noexcept {
        return buckets_.empty() ? 0.0
                                : static_cast<double>(size_) / buckets_.size();
    }

    void reserve(size_type n) {
        size_type need = static_cast<size_type>(n / kMaxLoadFactor) + 1;
        if (need > buckets_.size()) rehash_impl(need);
    }

    void clear() { clear_nodes(); }

    /* ---------------- 迭代器 ---------------- */
    iterator begin() {
        std::size_t b = 0;
        while (b < buckets_.size() && !buckets_[b]) ++b;
        return iterator(this, b, b < buckets_.size() ? buckets_[b] : nullptr);
    }
    iterator end() { return iterator(this, buckets_.size(), nullptr); }

    const_iterator begin() const {
        std::size_t b = 0;
        while (b < buckets_.size() && !buckets_[b]) ++b;
        return const_iterator(this, b, b < buckets_.size() ? buckets_[b] : nullptr);
    }
    const_iterator end() const {
        return const_iterator(this, buckets_.size(), nullptr);
    }
    const_iterator cbegin() const { return begin(); }
    const_iterator cend()   const { return end(); }

    /* ---------------- 插入 ---------------- */
    template<class K, class... Args>
    std::pair<iterator, bool> emplace(K&& key, Args&&... args) {
        if (buckets_.empty()) rehash_impl(kInitialCapacity);

        std::size_t idx = bucket_index(key, buckets_.size());
        for (Node* n = buckets_[idx]; n; n = n->next)
            if (eq_(n->kv.first, key))
                return {iterator(this, idx, n), false};   // 已存在，不覆盖

        if (static_cast<double>(size_ + 1) / buckets_.size() > kMaxLoadFactor) {
            rehash_impl(buckets_.size() * 2);
            idx = bucket_index(key, buckets_.size());     // 容量变了，重算
        }

        Node* n = new Node(std::forward<K>(key), std::forward<Args>(args)...);
        n->next = buckets_[idx];                          // 头插
        buckets_[idx] = n;
        ++size_;
        return {iterator(this, idx, n), true};
    }

    std::pair<iterator, bool> insert(const value_type& v) {
        return emplace(v.first, v.second);
    }

    std::pair<iterator, bool> insert(value_type&& v) {
        // value_type 的 first 是 const Key；元素整体是右值时可安全移动其 key。
        // 标准库实现（如 libstdc++ 的 map）也使用同样的 const_cast 技巧。
        return emplace(std::move(const_cast<Key&>(v.first)), std::move(v.second));
    }

    /* ---------------- 查找 ---------------- */
    iterator find(const Key& key) {
        if (buckets_.empty()) return end();
        std::size_t idx = bucket_index(key, buckets_.size());
        for (Node* n = buckets_[idx]; n; n = n->next)
            if (eq_(n->kv.first, key)) return iterator(this, idx, n);
        return end();
    }

    const_iterator find(const Key& key) const {
        if (buckets_.empty()) return end();
        std::size_t idx = bucket_index(key, buckets_.size());
        for (Node* n = buckets_[idx]; n; n = n->next)
            if (eq_(n->kv.first, key)) return const_iterator(this, idx, n);
        return end();
    }

    bool contains(const Key& key) const { return find(key) != end(); }

    T& at(const Key& key) {
        auto it = find(key);
        if (it == end()) throw std::out_of_range("HashMap::at: key not found");
        return it->second;
    }
    const T& at(const Key& key) const {
        auto it = find(key);
        if (it == end()) throw std::out_of_range("HashMap::at: key not found");
        return it->second;
    }

    T& operator[](const Key& key) { return emplace(key).first->second; }
    T& operator[](Key&& key)      { return emplace(std::move(key)).first->second; }

    /* ---------------- 删除 ---------------- */
    size_type erase(const Key& key) {
        if (buckets_.empty()) return 0;
        std::size_t idx = bucket_index(key, buckets_.size());
        Node** pp = &buckets_[idx];          // 二级指针，删头/中间统一处理
        while (*pp) {
            Node* n = *pp;
            if (eq_(n->kv.first, key)) {
                *pp = n->next;
                delete n;
                --size_;
                return 1;
            }
            pp = &n->next;
        }
        return 0;
    }

    iterator erase(iterator pos) {
        if (pos == end()) return end();
        iterator next = pos;
        ++next;
        erase(pos->first);
        return next;
    }
}

//应用
#include <iostream>
#include <string>

int main() {
    HashMap<std::string, int> m;
    m["apple"]  = 1;
    m["banana"] = 2;
    m.emplace("cherry", 3);
    m.insert({"date", 4});

    std::cout << "size = " << m.size()
              << ", buckets = " << m.bucket_count()
              << ", load = " << m.load_factor() << "\n";

    for (auto& [k, v] : m)
        std::cout << k << " = " << v << "\n";

    if (auto it = m.find("banana"); it != m.end())
        std::cout << "banana -> " << it->second << "\n";

    m.erase("apple");
    std::cout << "contains apple: " << std::boolalpha
              << m.contains("apple") << "\n";

    // 拷贝 / 移动
    HashMap<std::string, int> m2 = m;
    HashMap<std::string, int> m3 = std::move(m2);
    std::cout << "m3.size = " << m3.size() << ", m2.size = " << m2.size() << "\n";
}