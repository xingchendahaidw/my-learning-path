#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        char s[25]; 
        scanf("%s", s);
        
        int cnt[10] = {0};
        for (int i = 0; s[i] != '\0'; i++)
        {
            cnt[s[i] - '0']++;
        }
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                putchar('0' + i);
            }
        }
        putchar('\n');
    }
    return 0;
}
