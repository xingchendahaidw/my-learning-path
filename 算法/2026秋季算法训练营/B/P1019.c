#include <stdio.h>
#include <stdbool.h>

// 检查x个机器人是否能撑m天
bool check(long long x, long long n, long long k, long long m) {
    long long t = n;
    for (long long i = 0; i < m; i++) {
        long long bad = (t * k + 99) / 100; // 向上取整 t*k /100
        t -= bad;
        t -= x;
        if (t < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n, k, m;
    scanf("%lld %lld %lld", &n, &k, &m);
    long long l = 0, r = n;
    long long ans = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (check(mid, n, k, m)) {
            ans = mid;
            l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
