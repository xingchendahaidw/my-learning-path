#include<stdio.h>
int main()
{
    int a,b;
    int t;

    scanf("%d %d",&a,&b);
    int orga;
    int orgb;
    while (b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    printf("%d和%d的最大公约数是%d。\n",orga,orgb,a);
    return 0;
}