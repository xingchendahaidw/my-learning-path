
#include <iostream>
#include <string>
using namespace std;

int pos[15]; // 记录每个盘子当前所在的柱子 (1: A, 2: B, 3: C)
int n;
string s;
// 将 1~k 号盘子移动到 target 柱
void solve(int k, int target) {
    if (k == 0) return;
    
    if (pos[k] == target) {
        // 如果第 k 个盘子已经在目标柱上，只需把 1~k-1 移动到目标柱
        solve(k - 1, target);
    } else {
        // 如果第 k 个盘子不在目标柱上
        int source = pos[k];
        int aux = 6 - source - target; // 辅助柱 (A=1, B=2, C=3, 总和为6)
        
        // 1. 先把 1~k-1 个盘子移动到辅助柱
        solve(k - 1, aux);
        
        // 2. 把第 k 个盘子移动到目标柱
        printf("%c->%d->%c\n", 'A' + source - 1, k, 'A' + target - 1);
        pos[k] = target; // 更新当前盘子的位置
        
        // 3. 再把 1~k-1 个盘子从辅助柱移动到目标柱
        solve(k - 1, target);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (cin >> n >> s) {
        // 初始化盘子位置
        for (int i = 0; i < n; ++i) {
            pos[i + 1] = s[i] - 'A' + 1; 
        }
        
        // 目标是把所有盘子移动到 B 柱 (2)
        solve(n, 2);
    }
    
    return 0;
}