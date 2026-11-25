#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);
    while (k--)
    {
        int x;
        scanf("%d", &x);
        int first = 1; 

        for (int i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
            {
                if (first)
                {
                    printf("%d", i);
                    first = 0;
                }
                else
                {
                    printf("*%d", i);
                }
                x /= i;
            }
        }

       
        if (x > 1)
        {
            if (first)
                printf("%d", x);
            else
                printf("*%d", x);
        }
        printf("\n");
    }
    return 0;
}
