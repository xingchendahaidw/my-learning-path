#include <stdio.h>

int yanghui(int i, int j)
{
    if (j == 1 || j == i)
    {
        return 1;
    }
    return yanghui(i - 1, j - 1) + yanghui(i - 1, j);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%-4d", yanghui(i, j)); 
        }
        printf("\n");
    }
    return 0;
}
