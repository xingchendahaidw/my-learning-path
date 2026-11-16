#include<stdio.h>
int main()
{
    int m;
    scanf("%d",&m);

    int n,sum=0;
    while(m--)
    {
        n=0;
        sum=0;
        int x;
        do
        {
            scanf("%d",&x);
            sum+=x;
            n++;
        } while (x!=0);
        printf("%d\n",n*(n+1)/2-sum);
    }
    return 0;
}