#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9; // 用于初始化最小值

int main() {
    // 优化输入输出流速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 预处理前缀最值
    vector<int> pref_max(n + 2, -INF);
    vector<int> pref_min(n + 2, INF);
    for (int i = 1; i <= n; ++i) {
        pref_max[i] = max(pref_max[i - 1], a[i]);
        pref_min[i] = min(pref_min[i - 1], a[i]);
    }

    // 预处理后缀最值
    vector<int> suff_max(n + 2, -INF);
    vector<int> suff_min(n + 2, INF);
    for (int i = n; i >= 1; --i) {
        suff_max[i] = max(suff_max[i + 1], a[i]);
        suff_min[i] = min(suff_min[i + 1], a[i]);
    }

    // 处理每次询问
    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans_max = -INF;
        int ans_min = INF;

        // 如果 l > 1，说明左边有剩余部分
        if (l > 1) {
            ans_max = max(ans_max, pref_max[l - 1]);
            ans_min = min(ans_min, pref_min[l - 1]);
        }
        // 如果 r < n，说明右边有剩余部分
        if (r < n) {
            ans_max = max(ans_max, suff_max[r + 1]);
            ans_min = min(ans_min, suff_min[r + 1]);
        }

        cout << ans_max << " " << ans_min << "\n";
    }

    return 0;
}