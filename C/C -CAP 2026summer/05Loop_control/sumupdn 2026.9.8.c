#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    double num=0.0;
    int sign=1;
    for ( i = 1; i <= n; i++)
    {
        num+=sign*1.0/i;
        sign=-sign;
    }
    printf("f(%d)=%f",n,num);
    return 0;
}