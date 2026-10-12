#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int window = k + 1;
    int a[n+1];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    long long sum = 0;
    for(int i = 0; i < window; i++)
    {
        sum += a[i];
    }
    long long max_sum = sum;

    for(int i = window; i < n; i++)
    {
        sum = sum - a[i - window] + a[i];
        if(sum > max_sum)
        {
            max_sum = sum;
        }
    }
    printf("%lld\n", max_sum);
    return 0;
}
