#include<stdio.h>
int main ()
{
    int n;
    long p;
    printf("Input n:");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        p=p*i;
    }
    printf("%d!=%ld\n",n,p);
    return 0;
}