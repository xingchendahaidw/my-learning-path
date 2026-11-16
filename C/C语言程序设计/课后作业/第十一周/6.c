#include <stdio.h>

int main()
{
    int vul, d;
    while (scanf("%d %d", &vul, &d) == 2)
    {
        if (vul == 0 || d == 0)
            break;
        
        int total = (vul + d - 1) / d;
        
        int k = 0;          
        int sum_drops = 0;  
        
        while (sum_drops + (k + 1) < total)
        {
            k++;
            sum_drops += k;
        }
        
        int time = sum_drops + k;
        time += total - sum_drops;
        printf("%d\n", time);
    }
    return 0;
}
