/*std::queue 是 C++ 标准库（STL）中的队列容器适配器，定义在 <queue> 头文件中，遵循先进先出（FIFO）原则。
默认底层使用 std::deque 实现。常用操作包括：

    push / emplace：队尾入队

    pop：队首出队（返回 void，不返回元素）

    front：访问队首元素

    back：访问队尾元素

    empty：判断是否为空

    size：元素个数

queue 不支持迭代器、随机访问和遍历，只能访问队首和队尾。入队/出队通常是 O(1)O(1)。*/
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // 入队
    q.push(10);
    q.push(20);
    q.emplace(30);  // 原地构造并入队

    std::cout << "size = " << q.size() << "\n";
    std::cout << "front = " << q.front() << ", back = " << q.back() << "\n";

    // 依次出队
    std::cout << "出队顺序: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();  // pop 不返回元素，需要先 front()
    }
    std::cout << "\n";

    std::cout << "出队后 size = " << q.size() << "\n";

    return 0;
}