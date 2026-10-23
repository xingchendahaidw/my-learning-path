#include <stdio.h>

#define MOD 10007
#define MAXN 100005

// 记录每种颜色、每种奇偶性的统计信息
typedef struct {
    long long cnt;       // 出现次数
    long long sum_x;     // 下标之和
    long long sum_num;   // 数字之和
    long long sum_xn;    // 下标乘数字之和
} State;

State states[MAXN][2];
int number[MAXN];
int color[MAXN];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // 读取每个格子上的数字
    for (int i = 1; i <= n; i++) {
        scanf("%d", &number[i]);
    }
    // 读取每个格子上的颜色
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }

    // 遍历所有格子，按颜色和奇偶性分组统计
    for (int i = 1; i <= n; i++) {
        int c = color[i];
        int p = i % 2; // 0为偶数，1为奇数
        
        // 在累加过程中直接取模，防止溢出
        states[c][p].cnt = (states[c][p].cnt + 1) % MOD;
        states[c][p].sum_x = (states[c][p].sum_x + i) % MOD;
        states[c][p].sum_num = (states[c][p].sum_num + number[i]) % MOD;
        states[c][p].sum_xn = (states[c][p].sum_xn + (long long)i * number[i]) % MOD;
    }

    long long ans = 0;
    
    // 计算总贡献
    for (int c = 1; c <= m; c++) {
        for (int p = 0; p <= 1; p++) {
            long long cnt = states[c][p].cnt;
            long long sum_x = states[c][p].sum_x;
            long long sum_num = states[c][p].sum_num;
            long long sum_xn = states[c][p].sum_xn;

            // 项1：(cnt - 2) * sum_xn
            // 注意 cnt 可能为 1，此时 cnt - 2 为负数，需要加上 MOD 防止出现负数取模问题
            long long term1 = ((cnt - 2 + MOD) % MOD) * sum_xn % MOD;
            
            // 项2：sum_x * sum_num
            long long term2 = sum_x * sum_num % MOD;
            
            ans = (ans + term1 + term2) % MOD;
        }
    }

    printf("%lld\n", ans);
    return 0;
}