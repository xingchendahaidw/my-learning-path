#include<stdio.h>//流程的转移控制
int main()
{
    int i,n;
    for ( i = 1; i <=5; i++)
    {
        printf("Input n:");
        scanf("%d",&n);
        if(n<0) goto END;//goto是无条件转向语句
        printf("n=%d\n",n);
    }
    END:printf("Program is over.");
    return 0;
}
int main()
{
    int i,n;
    for ( i = 1; i <=5; i++)
    {
        printf("Input n:");
        scanf("%d",&n);
        if(n<0) break;
        printf("n=%d\n",n);
    }
    printf("Program is over.");
    return 0;
}