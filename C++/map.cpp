//std::map 是 C++ 标准库（STL）中的关联容器，定义在 <map> 头文件中。
//它存储键值对 std::pair<const Key, T>，其中键唯一且有序，默认按键的 operator< 升序排列，底层通常用红黑树实现。
//常用操作包括 operator[]、insert、emplace、find、count、erase、lower_bound 等，
//查找/插入/删除通常是 O(log?n)O(logn)。
//注意：map 的键是只读的，不能通过迭代器修改键；值可以修改。使用 operator[] 访问不存在的键时，会插入一个值初始化的元素。
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages;

    // 插入/赋值
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages.insert({"Charlie", 35});
    ages.emplace("David", 28);

    // 修改已有键的值
    ages["Bob"] = 26;

    std::cout << "size = " << ages.size() << "\n";

    // 遍历：按 key 升序排列
    std::cout << "元素:\n";
    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << "\n";
    }

    // 查找
    auto it = ages.find("Charlie");
    if (it != ages.end()) {
        std::cout << "找到 Charlie: " << it->second << "\n";
    }

    // count：map 中键唯一，返回 0 或 1
    std::cout << "count(Alice) = " << ages.count("Alice") << "\n";

    // 删除
    ages.erase("David");

    std::cout << "删除 David 后:\n";
    for (const auto& p : ages) {
        std::cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}