#include<stdio.h>
int main()
{
    int x,n;
    scanf("%d %d",&x,&n);

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(x>=1&&x<=5)
        {
            cnt++;
        }
        x++;
        if(x>7)x=1;
    }
    int ans;
    ans=250*cnt;
    printf("%d",ans);
    return 0;
}