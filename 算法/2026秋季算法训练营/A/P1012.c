#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int p[2000];  
    // 读入排列
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    while(1)
    {
        // shift操作：前移一位，第一个放到末尾
        int first = p[0];
        for(int i = 0; i < n - 1; i++)
        {
            p[i] = p[i+1];
        }
        p[n-1] = first;

        // 输出移位后的数组
        for(int i = 0; i < n; i++)
        {
            if(i > 0) printf(" ");
            printf("%d", p[i]);
        }
        printf("\n");

        if(p[n-1] == n)
        {
            break;
        }
    }
    return 0;
}