#include <stdio.h>
int main ()
{   
    int n,x;
    scanf("%d %d",&n,&x);
    int cnt=0;
    for (int i=1; i<=n; i++) 
    {
        int j=i;
        while (j>0) 
        {
            if (j%10==x) 
            {
                cnt++;
            }
            j=(j-j%10)/10;
        }
    }
    printf("%d",cnt);
    return 0;
}