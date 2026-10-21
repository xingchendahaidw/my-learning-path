#include<stdio.h>
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    if (M%N==0)
    {
        printf("YES");
    }else
    {
        printf("NO");
    }
    return 0;
}