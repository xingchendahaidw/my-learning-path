#include <stdio.h>
int main()
{
    char c;
    int n;
    while (scanf(" %c %d", &c, &n) == 2)
    {
        int width = 2 * n - 1;
        int mid = n - 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == n)
                {
                    putchar(c);
                }
                else if (j == mid - i+1 || j == mid+i-1)
                {
                    putchar(c);
                }
                else
                {
                    putchar('*');
                }
            }
            putchar('\n');
        }
    }
    return 0;
}