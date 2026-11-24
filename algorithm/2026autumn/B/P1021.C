#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000005

long long mice[MAX_SIZE];
long long holes[MAX_SIZE];
int n, m;

// 比较函数，供 qsort 使用
int cmp(const void *a, const void *b) {
    long long arg1 = *(const long long *)a;
    long long arg2 = *(const long long *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

long long llabs_custom(long long a) {
    return a < 0 ? -a : a;
}

// 检查在最大距离为 D 的情况下，是否能让所有老鼠进洞
int check(long long D) {
    int i = 0; // 指向老鼠的指针
    int j = 0; // 指向洞的指针
    
    while (i < n && j < m) {
        if (llabs_custom(mice[i] - holes[j]) <= D) {
            // 如果当前老鼠能进当前洞，匹配成功
            i++;
            j++;
        } else if (holes[j] < mice[i] - D) {
            // 如果当前洞太靠左，老鼠无法到达，跳过这个洞
            j++;
        } else if (holes[j] > mice[i] + D) {
            return 0; 
        }
    }
    // 如果所有老鼠都匹配到了洞
    return i == n;
}

int main() {
    // 读取输入
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &mice[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &holes[i]);
    }

    qsort(mice, n, sizeof(long long), cmp);
    qsort(holes, m, sizeof(long long), cmp);

    long long L = 0;
    long long r1 = llabs_custom(mice[0] - holes[m - 1]);
    long long r2 = llabs_custom(mice[n - 1] - holes[0]);
    long long R = r1 > r2 ? r1 : r2;

    long long ans = R;
    while (L <= R) {
        long long mid = L + (R - L) / 2;
        if (check(mid)) 
        { 
            ans = mid;    
            R = mid - 1;
        } else {
            L = mid + 1;  
        }
    }
    printf("%lld\n", ans);
    return 0;
}