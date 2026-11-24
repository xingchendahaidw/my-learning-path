#include <stdio.h>

int cnt[20] = {0};

int f(int i) {
    cnt[i]++;  // 每次进入f(i)，调用次数+1
    if (i == 0 || i == 1) {
        return 1;
    }
    return f(i - 1) + f(i - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    f(n);
    // 输出 cnt[0] 到 cnt[n]
    for (int i = 0; i <= n; i++) {
        if (i > 0) printf(" ");
        printf("%d", cnt[i]);
    }
    printf("\n");
    return 0;
}
