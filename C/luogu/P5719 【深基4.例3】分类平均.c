#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int sum1=0,cnt1=0;
    int sum2=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(i%k==0)
        {
            sum1+=i;
            cnt1++;
        }else
        {
            sum2+=i;
            cnt2++;
        }
    }
    double aver1=1.0*sum1/cnt1;
    double aver2=1.0*sum2/cnt2;
    printf("%.1f %.1f\n",aver1,aver2);
    return 0;
}