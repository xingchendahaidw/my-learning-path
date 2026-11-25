#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a;
        scanf("%d", &a);
        // 五个数：x0=a, x1=a+1, x2=a+2, x3=a+3, x4=a+4
        int x0 = a;
        int x1 = a+1;
        int x2 = a+2;
        int x3 = a+3;
        int x4 = a+4;

        // i,j,k,l,m 分别选5个位置，不能重复
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(j == i) continue;
                for(int k = 0; k < 5; k++)
                {
                    if(k == i || k == j) continue;
                    for(int l = 0; l < 5; l++)
                    {
                        if(l == i || l == j || l == k) continue;
                        for(int m = 0; m < 5; m++)
                        {
                            if(m == i || m == j || m == k || m == l) continue;
                            // 按下标取出数字输出
                            int arr[5] = {x0,x1,x2,x3,x4};
                            printf("%d%d%d%d%d\n", arr[i], arr[j], arr[k], arr[l], arr[m]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
