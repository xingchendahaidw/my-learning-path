#include <stdio.h>
#include <math.h> // fabsº¯Êý

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        if (a < 0)
        {
            printf("error\n");
            continue;
        }
        double x = a; // µü´ú³õÖµ
        double next;
        do
        {
            next = (x + a / x) / 2.0;
            if (fabs(next - x) < 0.00001)
                break;
            x = next;
        } while (1);
        printf("%.5f\n", next);
    }
    return 0;
}
