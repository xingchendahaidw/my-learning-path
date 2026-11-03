#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    long sum = 0;
    int term = 1;
    for (int i = 1; i <= n; i++)
    {
        term *= i;    // µÝÍÆ¼ÆËãi!
        sum += term;  // ÀÛ¼Ó
    }
    printf("%d\n", sum);
    return 0;
}
