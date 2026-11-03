#include<stdio.h>
//原始代码问题：case情况过于冗余，输出格式不够规范(\n)，扩展性不足，没有单一变量原则
int main1()
{
    int month,year;
    scanf("%d %d",&year,&month);
    //初始化月份,年份
    switch (month)
    {
    case 1:
        printf("31");
        break;
    case 2:
        if ((year%4==0&&year%100!=0)||year%400==0)
        {
            printf("29");
        } else
        {
            printf("28");
        }
        break;
    case 3:
        printf("31");
        break;
    case 4:
        printf("30");
        break;
    case 5:
        printf("31");
        break;
    case 6:
        printf("30");
        break;
    case 7:
        printf("31");
        break;
    case 8:
        printf("31");
        break;
    case 9:
        printf("30");
        break;
    case 10:
        printf("31");
        break;
    case 11:
        printf("30");
        break;
    case 12:
        printf("31");
        break;    
    default:
        printf("You have entered a wrong month.");
        break;
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int year, month, days;
    printf("请输入年份和月份：");
    scanf("%d %d", &year, &month);

    switch(month)
    {
        // 31天的月份
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        // 30天的月份
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        // 2月单独判断闰年
        case 2:
            if( (year%4 == 0 && year%100 != 0) || (year%400 == 0) )
                days = 29;
            else
                days = 28;
            break;
        // 月份不合法
        default:
            printf("输入的月份不合法！\n");
            return 0;
    }
    printf("%d年%d月有%d天\n", year, month, days);
    return 0;
}
