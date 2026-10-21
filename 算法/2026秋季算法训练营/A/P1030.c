#include <stdio.h>

int main() {
    int M, N;
    // 读取内存容量 M 和文章长度 N
    scanf("%d %d", &M, &N);
    int queue_arr[1005]; // 模拟内存队列，最多容纳1005个单词
    int head = 0, tail = 0; // 队列的头指针和尾指针
    int in_memory[1005] = {0}; // 标记单词是否在内存中，0表示不在，1表示在
    int lookup_count = 0;      // 访问外存的次数
    for (int i = 0; i < N; ++i) {
        int word;
        scanf("%d", &word);
        // 如果当前单词不在内存中
        if (in_memory[word] == 0) {
            lookup_count++; // 访问外存，次数+1
            // 如果内存已满（队列当前元素个数等于 M）
            if (tail - head == M) {
                int oldest_word = queue_arr[head];
                head++; // 头指针后移，相当于出队
                in_memory[oldest_word] = 0; // 标记该单词已不在内存中
            }
            // 将新单词存入内存（入队）
            queue_arr[tail] = word;
            tail++;
            in_memory[word] = 1; // 标记该单词在内存中
        }
    }
    // 输出需要去外存查找词典的次数
    printf("%d\n", lookup_count);

    return 0;
}