#include<stdio.h>
int main()
{
    int n;
    printf("Input n");
    scanf("%d",&n);
    int sum=0;
    for (int i = 1; i <=n; i++)
    {
        sum=sum+i;
    }
    printf("sum=%d\n",sum);
    return 0;
}
int main()
{
    int n;
    printf("Input n");
    scanf("%d",&n);
    int sum=0;
    int i = 1
    while(i<=n)
    {
        sum=sum+i;
        i++;
    }
    printf("sum=%d\n",sum);
    return 0;
}
int main()
{
    int n;
    printf("Input n");
    scanf("%d",&n);
    int sum=0;
    int i = 1
    do{
        sum=sum+i;
        i++;
    }while(i<=n);
    printf("sum=%d\n",sum);
    return 0;
}
//思考题
int main(void)
{
    int i, j, n, sum = 0;
    printf("Input n:");
    scanf("%d", &n);
    for (i=1, j=n; i < j; i++, j--)//逗号运算符：连接N个表达式，算式结果为第N个的结果
    {
        sum = sum + i + j;
    }
    // n为奇数时，补上中间未被累加的数
    if (i == j)
    {
        sum += i;
    }
    printf("sum = %d\n", sum);
    return 0;
}
//or
for (i=1, j=n; i <= j; i++, j--)
{
    if (i == j)
        sum += i;    // 中间数只加一次
    else
        sum += i + j;
}