#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    double num=0.0;
    for ( i = 1; i <= n; i++)
    {
        num+=1.0/i;
    }
    printf("f(%d)=%f",n,num);
    return 0;
}