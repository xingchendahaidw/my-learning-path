#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        int flag = 0;   //标记有没有找到水仙花数
        for (int i = m; i <= n; i++)
        {
            int a = i / 100;        //百位
            int b = (i / 10) % 10;  //十位
            int c = i % 10;         //个位
            if (a*a*a + b*b*b + c*c*c == i)
            {
                if (flag == 1)
                    printf(" ");
                printf("%d", i);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}
