#include<stdio.h>
int main()
{
    int year;
    scanf("%d",&year);
    
    int isLeap=0;
    if((year%4==0&&year%100!=0)||(year%400==0))
    {
        isLeap=1;
    }
    printf("%d",isLeap);
    return 0;
}