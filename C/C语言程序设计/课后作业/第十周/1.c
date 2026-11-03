#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        if (x >= 100 && x <= 999)
        {
            int a = x % 10;
            int b = x / 10 % 10;
            int c = x / 100;
            printf("%d,%d,%d\n", a, b, c);
        }
        else
        {
            printf("illegal\n");
        }
    }
    return 0;
}
