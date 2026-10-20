#include<stdio.h>
int main()
{
    int x=153,b0,b1,b2,sum;
    b2=x/100;
    b1=(x-b2*100)/10;
    b0=x%10;
    sum=b2+b1+b0;
    printf("sum=%d\n",sum);
    return 0;
}