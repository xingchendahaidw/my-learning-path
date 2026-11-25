#include <stdio.h>
int a[105][105] = {0};
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int num = 1;

    // 按对角线 s = i+j 遍历填充
    for (int s = 0; s <= m + n - 2; s++)
    {
        // 计算当前对角线行号的上下界
        int start = (s - (n - 1)) > 0 ? (s - (n - 1)) : 0;
        int end = (m - 1) < s ? (m - 1) : s;

        if (s % 2 == 0)
        {
            // 偶数条对角线：从左下往右上走（行号从大到小）
            for (int i = end; i >= start; i--)
            {
                int j = s - i;
                a[i][j] = num++;
            }
        }
        else
        {
            // 奇数条对角线：从右上往左下走（行号从小到大）
            for (int i = start; i <= end; i++)
            {
                int j = s - i;
                a[i][j] = num++;
            }
        }
    }

    // 输出矩阵
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
