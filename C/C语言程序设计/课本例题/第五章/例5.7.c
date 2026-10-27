#include <stdio.h>
#include <math.h>
#define EPS 1e-1

int main(void)
{
    float a, b, c;
    int flag = 1;

    printf("Input a,b,c:");
    scanf("%f,%f,%f", &a, &b, &c);

    // 判断是否能构成三角形
    if (a+b > c && b+c > a && a+c > b)
    {
        // 1. 先判断等边（最严格的特殊三角形）
        if (fabs(a-b)<=EPS && fabs(b-c)<=EPS && fabs(c-a)<=EPS)
        {
            printf("等边");
            flag = 0;
        }
        // 2. 再判断等腰
        else if (fabs(a-b)<=EPS || fabs(b-c)<=EPS || fabs(c-a)<=EPS)
        {
            printf("等腰");
            flag = 0;
        }

        // 3. 判断直角三角形（与等腰/等边不互斥，支持等腰直角的输出）
        if (fabs(a*a+b*b-c*c) <= EPS || fabs(a*a+c*c-b*b) <= EPS
            || fabs(c*c+b*b-a*a) <= EPS)
        {
            printf("直角");
            flag = 0;
        }

        // 都不满足则为一般三角形
        if (flag)
        {
            printf("一般");
        }
        printf("三角形\n");
    }
    else
    {
        printf("不是三角形\n");
    }

    return 0;
}
