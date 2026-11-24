#include<stdio.h>
#define MONTHS 12
int main()
{
    int days[MONTHS]={31,28,31,30,31,30,31,31,30,31,30,31};
    int month;
    do
    {
        printf("Input a month.");
        scanf("%d",&month);
    } while (month<1||month>12);
    printf("The number of the month is %d",days[month-1]);
    return 0;
}