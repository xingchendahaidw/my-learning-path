#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int max,min,x;
    while (n--)
    {
        for (int i = 1; i <=4; i++)
        {
            scanf("%d",&x);
            if(i == 1)  // 读到第一个数的时候初始化max、min
            {
                max = x;
                min = x;
            }
            else
            {
                if (x>max)
                {
                    max=x;
                }
                if (x<min)
                {
                    min=x;
                }
            }
        }
        printf("%d %d\n",max,min);
    }
    return 0;
}
