#include<stdio.h>
int main()
{
    float x;
    scanf("%f",&x);
    if(x>=0)
    printf("%lf",x);
    else
    printf("%lf",-x);
    return 0;
}