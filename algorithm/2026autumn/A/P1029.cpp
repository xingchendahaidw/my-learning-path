#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 1. 优化输入输出速度(这两行真的很好用)
    ios_base::sync_with_stdio(false); // 关闭 C 和 C++ 标准流的同步，加快 cin/cout 速度
    cin.tie(NULL);                    // 解除 cin 和 cout 的绑定，进一步提高速度

    int n, k;
    // 2. 读取 n 和 k
    if (!(cin >> n >> k)) return 0;   // 如果读取失败，直接结束程序

    // 3. 定义一个哈希表
    // 键(Key)是数组中的数值，值(Value)是一个 vector，用来存储该数值出现的所有下标
    unordered_map<int, vector<int>> occurrences;

    // 4. 循环遍历数组的每一个元素（题目要求下标从 1 开始）
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x; // 读取当前元素的值

        // 5. 将当前下标 i 存入 x 对应的 vector 中
        occurrences[x].push_back(i); 

        // 6. 判断当前数值出现的总次数是否达到了 k
        if (occurrences[x].size() >= k) {
            // 如果达到了 k 次，我们需要找包含最近的 k 个 x 的最短区间
            // 最短区间的左端点，就是当前 vector 里的倒数第 k 个元素的下标
            // 下标计算：当前长度 size()，倒数第 k 个就是 size() - k
            cout << occurrences[x][occurrences[x].size() - k] << "\n";
        } else {
            // 如果出现次数还不够 k 次，说明找不到满足条件的区间，输出 -1
            cout << -1 << "\n";
        }
    }

    return 0;
}