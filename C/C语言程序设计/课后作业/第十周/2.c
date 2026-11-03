#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        int cnt = 0;
        while (x > 0)
        {
            cnt += x & 1; // 取最低位
            x >>= 1;      // 右移一位
        }
        printf("%d\n", cnt);
    }
    return 0;
}
