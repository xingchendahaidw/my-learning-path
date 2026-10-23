#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long sum = 0;     
    long long ans = 0;     // 答案：最大值的下界

    for (int i = 1; i <= n; i++) {
        long long x;
        scanf("%lld", &x);

        sum += x;

        // 计算 ceil(sum / i)
        long long cur = (sum + i - 1) / i;

        if (cur > ans) ans = cur;
    }

    printf("%lld\n", ans);
    return 0;
}