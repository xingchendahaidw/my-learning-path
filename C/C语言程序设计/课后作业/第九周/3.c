#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n,a,sum;
    for (int i = 1; i <= t; i++)
    {
        sum = 0;
        int max = 0;   // 每组开始，max重置！
        scanf("%d",&n);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&a);
            sum += a;
            if (a > max)
            {
                max = a;
            }
        }
        // 读完一组所有数字，才输出一次
        double avg = 1.0 * sum / n;
        printf("%d %.2f\n", max, avg);
    }
    return 0;
}
