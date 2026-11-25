#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int m;
        scanf("%d", &m);
        int a[10][10] = {0};
        int num = 1;

        // 按斜线填充：每条斜线上 i+j = s，从左下往右上填
        for (int s = 0; s < m; s++)
        {
            for (int i = s; i >= 0; i--)
            {
                int j = s - i;
                a[i][j] = num++;
            }
        }

        // 按行输出三角形
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m - i; j++)
            {
                if (j > 0)
                    printf(" ");
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}