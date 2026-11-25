#include <stdio.h>
//暴力算法
int M, N;
int a[15][15];

// 递归函数：返回从(i,j)到右下角的最小路径和
int dfs(int i, int j)
{
    if (i == M-1 && j == N-1)
        return a[i][j];
    
    if (i == M-1)
        return a[i][j] + dfs(i, j+1);
    
    if (j == N-1)
        return a[i][j] + dfs(i+1, j);
    
    int down = dfs(i+1, j);
    int right = dfs(i, j+1);
    return a[i][j] + (down < right ? down : right);
}

int main()
{
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d\n", dfs(0, 0));
    return 0;
}

#include <stdio.h>
int main()
{
    int M, N;
    scanf("%d%d", &M, &N);
    int a[15][15];
    int dp[15][15];

    // 读取矩阵
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    dp[0][0] = a[0][0];
    // 初始化第一行
    for (int j = 1; j < N; j++)
    {
        dp[0][j] = dp[0][j-1] + a[0][j];
    }
    // 初始化第一列
    for (int i = 1; i < M; i++)
    {
        dp[i][0] = dp[i-1][0] + a[i][0];
    }

    // 填充dp数组
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            int min_prev = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            dp[i][j] = a[i][j] + min_prev;
        }
    }

    printf("%d\n", dp[M-1][N-1]);
    return 0;
}
