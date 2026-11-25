#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int rabbit = (y - 2 * x) / 2;
        int chicken = x - rabbit;
        // ÅÐ¶ÏÊÇ·ñºÏ·¨
        if(y % 2 == 0 && chicken >= 0 && rabbit >= 0 && (2*chicken + 4*rabbit == y))
        {
            printf("%d %d\n", chicken, rabbit);
        }
        else
        {
            printf("error\n");
        }
    }
    return 0;
}
