#include <stdio.h>
int gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);

    long long sum_num = 0;
    long long sum_den = 1;

    for (int i = 0; i < n; i++)
    {
        long long p, q;
        scanf("%lld/%lld", &p, &q); 
        long long new_num = sum_num * q + p * sum_den;
        long long new_den = sum_den * q;

        long long g = gcd(new_num, new_den);
        sum_num = new_num / g;
        sum_den = new_den / g;
    }

    if (sum_den == 1)
        printf("%lld\n", sum_num);
    else
        printf("%lld/%lld\n", sum_num, sum_den);

    return 0;
}
int main ()
{
    int n;
    scanf("%d",&n);

    int found=0;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            int k = n - i - j; 
            if(k < 0) continue;
            if(15*i + 9*j + k == 3*n)
            {
                printf("%d %d %d\n", i, j, k);
                found = 1;
            }
        }
    }
    if(found == 0)
    {
        printf("NO\n");
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int found = 0;

    
    for (int x = 0; 7 * x <= n; x++)
    {
        int rem = n - 7 * x;
        if (rem % 4 == 0)
        {
            int y = rem / 4;
            int z = n - x - y;
            printf("%d %d %d\n", x, y, z);
            found = 1;
        }
    }

    if (!found)
    {
        printf("NO\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    char s[110];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    if (s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            
            s[i] = (s[i] - 'A' + 4) % 26 + 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (s[i] - 'a' + 4) % 26 + 'a';
        }
}
    printf("%s\n", s);
    return 0;
}
