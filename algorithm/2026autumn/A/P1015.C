#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if(x < y) return -1;
    else if(x > y) return 1;
    else return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long *a = (long long*)malloc(n * sizeof(long long));
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    qsort(a, n, sizeof(long long), cmp);

    long long ans = 0;
    int i = 0;
    while(i < n)
    {
        int j = i;
        // 找到所有和a[i]相同的元素
        while(j < n && a[j] == a[i])
        {
            j++;
        }
        int cnt = j - i;
        ans += (long long) cnt * cnt;
        i = j;
    }
    printf("%lld\n", ans);
    return 0;
}