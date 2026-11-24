#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        long long a;
        scanf("%lld", &a);
        int cnt0 = 0, cnt1 = 0;
        long long x = a;
        while(x > 0)
        {
            int bit = x & 1;
            if(bit == 1)
                cnt1++;
            else
                cnt0++;
            x >>= 1;
        }
        if(cnt0 == cnt1)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}