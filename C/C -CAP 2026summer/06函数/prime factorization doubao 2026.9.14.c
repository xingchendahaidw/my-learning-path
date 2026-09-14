#include <stdio.h>
int main()
{
    int n, origin, i;
    scanf("%d", &n);
    origin = n;
    printf("%d=", origin);
    int first = 1;
    for(i=2;i*i<=n;i++)
    {
        while(n%i == 0)
        {
            if(!first) printf("x");
            printf("%d",i);
            first = 0;
            n /= i;
        }
    }
    if(n>1)
    {
        if(!first) printf("x");
        printf("%d",n);
    }
    return 0;
}
