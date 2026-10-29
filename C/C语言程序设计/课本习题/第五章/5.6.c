#include <stdio.h>
int main(void)
{
    int year, flag;
    printf("Enter year:");
    scanf("%d", &year);
    flag = ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ) ? 1 : 0;//条件表达式
    if ( flag == 1 )
        printf("%d is a leap year!\n",year);
    else
        printf("%d is not a leap year!\n",year);
    return 0;
}
