#include<stdio.h>
int main()
{
    int a,b,max;
    printf("Input a,b:");
    scanf("%d,%d",&a,&b);
    if (a>b)
    {
        max=a;
    } else
    {
        max=b;
    }
    printf("max=%d\n",max);
    return 0;
}