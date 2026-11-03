#include<stdio.h>
int main()
{
    int h,w,t;
    scanf("%d %d",&h,&w);

    //计算t
    t=w/(h*h);
    if (t<18)
    {
        printf("是低体重");
    }
    if (t>=18&&t<25)
    {
        printf("是正常体重");
    }
    if (t>=25&&t<27)
    {
        printf("是超重体重");
    }
    if (t>=27)
    {
        printf("是肥胖");
    }
    return 0;
}
#include <stdio.h>
int main()
{
    double h, w, t;
    printf("请输入身高(米)和体重(千克)：");
    scanf("%lf %lf", &h, &w);

    t = w / (h * h);
    printf("体指数 t = %.2lf\n", t);

    if(t < 18)
        printf("体型：低体重\n");
    else if(t < 25)   // 执行到此处说明 t >= 18
        printf("体型：正常体重\n");
    else if(t < 27)   // 执行到此处说明 t >= 25
        printf("体型：超重体重\n");
    else              // 执行到此处说明 t >= 27
        printf("体型：肥胖\n");

    return 0;
}
