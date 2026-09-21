#include<stdio.h>
int main()
{
    int n;
    int i=1;
    int factorial=1;
    scanf("%d",&n);
    while (i<=n)
    {
        factorial*=i;
        i++;
    }
    printf("%d %d",n,factorial);
    return 0;
}