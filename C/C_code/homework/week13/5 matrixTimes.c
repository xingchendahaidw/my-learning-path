#include<stdio.h>
int a[3][3],b[3][3];
int main()
{
    int n;
    scanf("%d",&n);
    
    while (n--)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j!=0)
                {
                    printf(" ");
                }
                printf("%d",a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j]);
                if(j==2)printf("\n");
            }
        }
    }
    return 0;
}