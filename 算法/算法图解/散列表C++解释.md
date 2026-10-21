
设计要点
1. 模板参数与自定义哈希
cpp

template<class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>>

默认用标准库的 std::hash 和 std::equal_to，但用户可以传入自定义函数对象：
cpp

struct MyHash { std::size_t operator()(const MyKey&) const; };
struct MyEq   { bool operator()(const MyKey&, const MyKey&) const; };
HashMap<MyKey, Value, MyHash, MyEq> m;

2. 节点与存储结构
cpp

struct Node {
    std::pair<const Key, T> kv;   // first 为 const，外部无法篡改 key
    Node* next;
};
std::vector<Node*> buckets_;

    用 std::pair<const Key, T> 而不是 Key key; T value;，让迭代器返回类型与标准 unordered_map 一致；

    buckets_ 用 std::vector 而不是裸数组，天然获得大小管理、swap 等能力；

    冲突仍然是链地址法头插法，O(1) 插入。

3. 迭代器：跨越空桶
text

bucket 0: [A] -> [B]
bucket 1: (空)
bucket 2: [C]
bucket 3: (空)

operator++ 的核心逻辑：
cpp

node_ = node_->next;
while (!node_) {              // 当前链走完
    ++bucket_;
    if (bucket_ >= buckets_.size()) break;   // 到末尾 → end()
    node_ = buckets_[bucket_];               // 找下一个非空桶
}

iterator 与 const_iterator 用同一个模板 basic_iterator<IsConst> 实现，靠 std::conditional_t 切换指针类型，避免了写两份几乎相同的代码。
4. Rule of Five
函数	实现方式
析构	遍历所有桶 delete 节点
拷贝构造	新建空桶，逐元素 emplace
拷贝赋值	copy-and-swap：先拷贝临时对象，再 swap，自动异常安全
移动构造	直接 std::move 窃取 buckets_，被移走的对象重置为空表
移动赋值	clear_nodes() 后窃取；被移走对象清空

移动构造/赋值的 noexcept 用 std::is_nothrow_move_constructible_v<hasher> 等条件推导，这样当 Hash/KeyEqual 是空类时，整个容器 move 是 noexcept，可被 std::vector<HashMap> 等容器高效使用。
5. 异常安全

    emplace 中若 new Node(...) 抛异常（比如 T 的构造抛），节点未插入链表，表结构不变 —— 强异常保证。

    rehash_impl 先在新 vector 上构造成功，最后 swap 才生效，失败时旧表不动。

    operator[] 在 key 不存在时默认构造 T，因此 T 需要可默认构造（与 std::unordered_map 一致）。

    at 在 key 不存在时抛 std::out_of_range，与标准库行为一致。

6. 扩容策略
cpp

if ((size_ + 1) / buckets_.size() > 0.75)
    rehash_impl(buckets_.size() * 2);

和 C 版一致：装填因子超过 0.75 时容量翻倍，rehash 是 O(n)，但由于容量翻倍，摊还到每次插入是 O(1)。
7. 关于 insert(value_type&&) 的 const_cast

value_type 是 std::pair<const Key, T>，其 first 是 const 的，严格来说无法移动。但传入的是右值、原对象会销毁时，移动其 key 是安全的。标准库容器（如 libstdc++ 的 std::map）内部也采用这种技巧。如果保守起见，可以改成 emplace(v.first, std::move(v.second))，代价是多一次 key 拷贝。
复杂度
操作	平均	最坏
emplace / insert	O(1) 摊还	O(n)
find / contains / at / operator[]	O(1)	O(n)
erase	O(1)	O(n)
迭代一遍	O(n + bucket_count)	—
说明

生产代码直接使用 std::unordered_map 即可，它经过了充分的工程优化（节点池、哈希缓存、异常安全、allocator 支持等）。这里的实现主要用于理解哈希表原理，以及作为需要定制哈希策略、特殊内存管理时的起点。

如果还想进一步，可以考虑：

    开放寻址 / Robin Hood / Swiss Table 风格，缓存更友好；

    树化：单桶链过长时转为红黑树（Java 8 HashMap 的做法），把最坏情况压到 O(log n)；

    节点池：用 std::pmr 或自定义 allocator 减少 new/delete 开销；

    heterogeneous lookup：允许用 const char* 直接查 std::string key，避免临时构造（C++20 透明哈希）；

    缩容：删除到一定程度时缩容，避免空间长期浪费。