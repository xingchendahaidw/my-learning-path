#include <stdio.h>
int main()
{
    int k;
    scanf("%d", &k);
    while (k--)
    {
        int m,n,tmp;
        scanf("%d %d",&m,&n);
        int orgm=m;
        int orgn=n;
        while (n!=0)
        {
            tmp=m%n;
            m=n;
            n=tmp;
        }
        printf("%d\n",orgm*orgn/m);
    }
    return 0;
}