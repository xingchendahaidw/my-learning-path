#include <stdio.h>

#define MAXN 100005
#define INF 2000000000

int a[MAXN];
int pref_max[MAXN];
int pref_min[MAXN];
int suff_max[MAXN];
int suff_min[MAXN];

// 自定义求最大值和最小值函数
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    // 初始化边界
    pref_max[0] = -INF;
    pref_min[0] = INF;
    
    // 计算前缀最值
    for (int i = 1; i <= n; ++i) {
        pref_max[i] = max(pref_max[i - 1], a[i]);
        pref_min[i] = min(pref_min[i - 1], a[i]);
    }

    // 初始化边界
    suff_max[n + 1] = -INF;
    suff_min[n + 1] = INF;

    // 计算后缀最值
    for (int i = n; i >= 1; --i) {
        suff_max[i] = max(suff_max[i + 1], a[i]);
        suff_min[i] = min(suff_min[i + 1], a[i]);
    }

    // 处理询问
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);

        int ans_max = -INF;
        int ans_min = INF;

        // 取左段最值
        if (l > 1) {
            ans_max = max(ans_max, pref_max[l - 1]);
            ans_min = min(ans_min, pref_min[l - 1]);
        }
        
        // 取右段最值
        if (r < n) {
            ans_max = max(ans_max, suff_max[r + 1]);
            ans_min = min(ans_min, suff_min[r + 1]);
        }

        printf("%d %d\n", ans_max, ans_min);
    }

    return 0;
}