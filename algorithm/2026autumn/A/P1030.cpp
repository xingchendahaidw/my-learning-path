#include <iostream>
#include <queue>

using namespace std;

int main() {
    int M, N;
    // 读取内存容量 M 和文章长度 N
    if (!(cin >> M >> N)) return 0;

    queue<int> memory;      // 模拟内存，存放单词
    bool in_memory[1005] = {false}; // 标记单词是否在内存中，初始为空
    int lookup_count = 0;   // 访问外存的次数

    for (int i = 0; i < N; ++i) {
        int word;
        cin >> word;
        // 如果当前单词不在内存中
        if (!in_memory[word]) {
            lookup_count++; // 需要去外存查找，次数+1
            // 如果内存已满，需要清空最早进入内存的单词
            if (memory.size() == M) {
                int oldest_word = memory.front();
                memory.pop();
                in_memory[oldest_word] = false; // 标记为不在内存
            }
            // 将新单词存入内存
            memory.push(word);
            in_memory[word] = true;
        }
    }
    // 输出需要去外存查找词典的次数
    cout << lookup_count << endl;

    return 0;
}