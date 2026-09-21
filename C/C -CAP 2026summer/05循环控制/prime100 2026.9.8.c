#include<stdio.h>
int main()
{
    int input;
    scanf("%d",&input);
    int i,j;
    int isPrime=1;
    int cnt=0;
    for ( i=2;cnt<=input; i++)
    {
        isPrime=1;
        for ( j=2; j<i; j++)
    {
        if (i%j==0)
        {
            isPrime=0;
            continue;
        }
        
    }
        if(isPrime==1)
        {
            printf("%d\t",i);
        }
    }
    return 0;
}