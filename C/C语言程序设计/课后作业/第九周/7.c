#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int ans = -1;
        // ÈËÊý·¶Î§£º10 ~ 100
        for (int x = 10; x <= 100; x++)
        {
            if (x % 3 == a && x % 5 == b && x % 7 == c)
            {
                ans = x;
                break;
            }
        }
        if (ans != -1)
            printf("%d\n", ans);
        else
            printf("Impossible\n");
    }
    return 0;
}
