#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int limit = 1;
    for (int i = 0; i < n; ++i) {
        limit *= 10;
    }
    int count = 0;
    for (int num = 1; num < limit; ++num) {
        int sum = 0;
        int tmp = num;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum <= k) {
            ++count;
        }
    }
    printf("%d\n", count);
    return 0;
}