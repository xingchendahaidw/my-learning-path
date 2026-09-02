#include<stdio.h>

int main()
{
    int a=0,b=0,c=0,d=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int e=(60*c-60*a+d-b)/60;
    int f=(60*c-60*a+d-b)%60;
    printf("%d %d",e,f);
    
    return 0;
}
