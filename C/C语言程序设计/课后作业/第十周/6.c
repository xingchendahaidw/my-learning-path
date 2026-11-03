#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        int num = x;
        // ÒÀ´Î³ý¾¡2¡¢3¡¢5
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        if (num == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}