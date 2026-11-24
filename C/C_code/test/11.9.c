1.#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int sum1 = 0;
    for(int i = 1; i <= n; i++)
    {
        sum1 += i;
    }
    printf("%d\n", sum1);
    int sum2 = 0;
    int i = 1;
    while(i <= n)
    {
        sum2 += i;
        i++;
    }
    printf("%d\n", sum2);
    int sum3 = 0;
    i = 1;
    do
    {
        sum3 += i;
        i++;
    }while(i <= n);
    printf("%d\n", sum3);
    return 0;
}
2.#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int m, n;
        scanf("%d %d", &m, &n);
         while(b != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
        printf("%d\n",m);
    }
    return 0;
}
3.#include <stdio.h>
int isPrime(int x)
{
    if(x < 2) return 0;
    for(int i = 2; i*i <= x; i++)
    {
        if(x % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        
        for(int i = 2; i <= n; i++)
        {
            if(isPrime(i))
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
4.#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (2*a + 2*b + c == n)
                {
                    int num = a*10000 + b*1000 + c*100 + b*10 + a;
                    printf("%d\n", num);
                }
            }
        }
    }
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (2*a + 2*b + 2*c == n)
                {
                    int num = a*100000 + b*10000 + c*1000 + c*100 + b*10 + a;
                    printf("%d\n", num);
                }
            }
        }
    }
    return 0;
}
