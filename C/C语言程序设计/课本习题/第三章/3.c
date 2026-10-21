#include<stdio.h>
#include<math.h>
int main()
{
    double capital,rate=0.0225,deposit;
    int n;
    printf("请输入存款本金");
    scanf("%lf",&capital);
    printf("请输入存款年份");
    scanf("%d",&n);
    deposit=capital*pow(1+rate,n);//pow(底数，指数)，幂次
    printf("%d年后的本利和为：%.2lf元\n",n,deposit);
    return 0;
}