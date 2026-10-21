//std::set 是 C++ 标准库（STL）中的关联容器，定义在 <set> 头文件中。
//它存储唯一且有序的元素，默认按 operator< 升序排列，底层通常用红黑树实现。
//常用操作包括 insert、erase、find、count、lower_bound、upper_bound 等，
//查找/插入/删除通常是 O(log?n)O(logn)。由于元素有序且唯一，重复插入不会生效；
//迭代器指向的元素是只读的，不能直接修改元素值。
#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    // 插入元素
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10);  // 重复元素，不会插入

    std::cout << "size = " << s.size() << "\n";

    // 遍历：set 会自动按升序排列
    std::cout << "元素: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // 查找
    if (s.find(20) != s.end()) {
        std::cout << "找到 20\n";
    } else {
        std::cout << "未找到 20\n";
    }

    // count：set 中元素唯一，返回 0 或 1
    std::cout << "count(10) = " << s.count(10) << "\n";

    // lower_bound：第一个 >= 15 的元素
    auto it = s.lower_bound(15);
    if (it != s.end()) {
        std::cout << "lower_bound(15) = " << *it << "\n";
    }

    // 删除元素
    s.erase(10);

    std::cout << "删除 10 后: ";
    for (const auto& x : s) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}