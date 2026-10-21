//std::vector 是 C++ 标准库（STL）中的动态数组容器，定义在 <vector> 头文件中。
//它支持自动扩容、连续内存存储和随机访问，常用操作包括 push_back、pop_back、size、operator[]、at、begin/end 等。
//尾部插入通常是均摊 O(1)O(1)，随机访问是 O(1)O(1)，中间插入/删除是 O(n)O(n)。
//扩容可能导致迭代器、指针和引用失效。
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v;          // 创建一个空的 int 向量

    v.push_back(10);             // 尾部添加元素
    v.push_back(20);
    v.emplace_back(30);          // 原地构造并添加到尾部

    std::cout << "size = " << v.size() << "\n";
    std::cout << "capacity = " << v.capacity() << "\n";

    // 范围 for 遍历
    std::cout << "元素: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // 随机访问
    v[0] = 15;
    std::cout << "v.at(1) = " << v.at(1) << "\n";

    // 删除最后一个元素
    v.pop_back();

    // 排序
    std::sort(v.begin(), v.end());

    std::cout << "排序后: ";
    for (const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
