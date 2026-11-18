#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long f[50];
    f[1]=1; f[2]=1;
    for(int i=3;i<=n;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    for(int i=n;i>=1;i--)
    {
        if(i!=n) printf(" ");
        printf("%lld", f[i]);
    }
    return 0;
}
