#include<stdio.h>
//原版，没有处理异常数据，没有做到单一出口
int main()
{
    int score;
    scanf("%d",&score);
    //输入数据
    if (score<=100&&score>=90)
    {
        putchar('A');
    }else if (score>=80)
    {
        putchar('B');
    }else if (score>=70)
    {
        putchar('C');
    }else if (score>=60)
    {
        putchar('D');
    }else if (score>=0)
    {
        putchar('E');
    }
    return 0;
}
//AI版
#include<stdio.h>
int main(void)
{
    int score;
    char grade;
    printf("请输入百分制成绩：");
    scanf("%d",&score);

    if(score >= 90 && score <= 100)
    {
        grade = 'A';
    }
    else if(score >= 80)
    {
        grade = 'B';
    }
    else if(score >= 70)
    {
        grade = 'C';
    }
    else if(score >= 60)
    {
        grade = 'D';
    }
    else if(score >= 0)
    {
        grade = 'E';
    }
    else
    {
        printf("输入成绩不合法！\n");//最后一个else处理不合法成绩
        return 0;
    }
    printf("grade = %c\n",grade);//单一出口原则
    return 0;
}
