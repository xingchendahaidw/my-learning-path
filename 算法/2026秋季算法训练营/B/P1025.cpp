#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

struct State {
    long long cnt = 0;       // 数量
    long long sum_x = 0;     // 下标之和
    long long sum_num = 0;   // 数字之和
    long long sum_xn = 0;    // 下标 * 数字 之和
};

int main() {
    // 优化输入输出流速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> number(n + 1);
    vector<int> color(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> number[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    // states[颜色][奇偶性]
    vector<vector<State>> states(m + 1, vector<State>(2));

    for (int i = 1; i <= n; i++) {
        int c = color[i];
        int p = i % 2;
        
        states[c][p].cnt = (states[c][p].cnt + 1) % MOD;
        states[c][p].sum_x = (states[c][p].sum_x + i) % MOD;
        states[c][p].sum_num = (states[c][p].sum_num + number[i]) % MOD;
        states[c][p].sum_xn = (states[c][p].sum_xn + 1LL * i * number[i]) % MOD;
    }

    long long ans = 0;
    for (int c = 1; c <= m; c++) {
        for (int p = 0; p <= 1; p++) {
            long long cnt = states[c][p].cnt;
            long long sum_x = states[c][p].sum_x;
            long long sum_num = states[c][p].sum_num;
            long long sum_xn = states[c][p].sum_xn;

            // 防止负数取模，加上 MOD
            long long term1 = ((cnt - 2 + MOD) % MOD) * sum_xn % MOD;
            long long term2 = sum_x * sum_num % MOD;
            
            ans = (ans + term1 + term2) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}