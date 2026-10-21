#include<stdio.h>
int main()
{
    int a,b,max;
    printf("Input a,b");
    scanf("%d,%d",&a,&b);
    max=a>b?a:b;//∑«0‘Úa∑Ò‘Úb
    printf("max=%d\n",max);
    return 0;
}