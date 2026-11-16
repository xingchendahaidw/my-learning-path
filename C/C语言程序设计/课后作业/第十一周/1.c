#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        int x;
        scanf("%d",&x);
        int cnt=0;
        while(x!=0)
        {
            if(x%2==1)
            {
                cnt++;
            }
            x/=2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}