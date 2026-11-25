#include<stdio.h>
#define MAXN 1010
int a[MAXN][MAXN],b[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            b[i][j]=a[j][i];
        }
    }
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (j > 0) printf(" "); // 数字之间加空格
            printf("%d", a[i][j] + b[i][j]);
        }
        printf("\n"); // 一行结束换行
    }
    return 0;
}