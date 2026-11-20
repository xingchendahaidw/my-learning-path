#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int ans;
    scanf("%d",&ans);
    for(int i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x<ans)
        {
            ans=x;
        }
    }
    printf("%d\n",ans);
    return 0;
}