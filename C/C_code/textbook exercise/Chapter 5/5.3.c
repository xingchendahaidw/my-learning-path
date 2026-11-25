#include <stdio.h>
#include <math.h>  

int main(void)
{
    double a, b, c;
    printf("请输入三角形的三边长：");
    scanf("%lf%lf%lf", &a, &b, &c);

    // 判断是否满足三角形构成条件：任意两边之和大于第三边
    if (a + b > c && a + c > b && b + c > a)
    {
        double s = (a + b + c) / 2.0;       // 计算半周长
        double area = sqrt(s * (s - a) * (s - b) * (s - c));  // 海伦公式求面积
        printf("能构成三角形，面积为：%.2lf\n", area);
    }
    else
    {
        printf("不能构成三角形\n");
    }

    return 0;
}
