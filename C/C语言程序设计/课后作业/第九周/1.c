#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",x/100+x%10+x/10%10);
    return 0;
}