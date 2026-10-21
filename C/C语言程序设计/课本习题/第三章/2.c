#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x;
    scanf("%d",&x);
    x=abs(x);//abs(int)È¡¾ø¶ÔÖµ
    printf("%d",x%10);
    printf("%d",x/10%10);
    printf("%d",x/100);
    return 0;
}