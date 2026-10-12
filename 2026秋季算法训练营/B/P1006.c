#include <stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (m == 0) {
        printf("0\n");
        return 0;
    }

    int a[3005];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int current_sum = 0;
    for (int i = 0; i < m; ++i) {
        current_sum += a[i];
    }
    int min_sum = current_sum;
    for (int i = m; i < n; ++i) {
        current_sum += a[i] - a[i - m];
        if (current_sum < min_sum) {
            min_sum = current_sum;
        }
    }

    printf("%d\n", min_sum);
    return 0;
}