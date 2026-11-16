#include<stdio.h>
int main()
{
    int k;
    scanf("%d",&k);

    while(k--)
    {
        int n;
        scanf("%d",&n);

        int cnt2=0,cnt5=0;
        for(int i=1;i<=n;i++)
        {
            int temp=i;
            while(temp%5==0)
            {
                temp/=5;
                cnt5++;
            }
            while(temp%2==0)
            {
                temp/=2;
                cnt2++;
            }
        }
        printf("%d\n",cnt5);
    }
    return 0;
}