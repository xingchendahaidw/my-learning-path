#include<stdio.h>
int main()
{
    int i,n;
    for ( i = 1; i <=5; i++)
    {
        printf("Input n:");
        scanf("%d",&n);
        if(n<0) continue;
        printf("n=%d\n",n);
    }
    printf("Program is over.");
    return 0;
}