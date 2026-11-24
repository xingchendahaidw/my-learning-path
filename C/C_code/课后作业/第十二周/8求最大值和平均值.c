#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int n;
        scanf("%d", &n);
        
        int max_val;
        double sum = 0.0;
        
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            if (i == 0)
            {
                max_val = x; 
            }
            else if (x > max_val)
            {
                max_val = x;
            }
            sum += x;
        }
        
        double avg = sum / n;
        printf("%d %.2f\n", max_val, avg);
    }
    return 0;
}
