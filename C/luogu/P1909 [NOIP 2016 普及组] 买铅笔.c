#include<stdio.h>
int min(int a,int b);
int main()
{
    int n,a,b;
    scanf("%d",&n);
    
    int ans=1e9;//格式转换，应改为10000000；
    for (int  i = 1; i <=3; i++)
    {
        scanf("%d %d",&a,&b);
        if(n%a==0)
        {
            ans=min(ans,n/a*b);
        }else
        {
            ans=min(ans,(n/a+1)*b);
        }
    }
    printf("%d",ans);
    return 0;
}
int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }else
    {
        return a;
    }
}