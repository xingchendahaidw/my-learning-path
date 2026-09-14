#include<stdio.h>
int main()
{
    int input;
    scanf("%d",&input);
    int i,j;
    int cnt=0;
    int isPrime=1;
    for(i=2;cnt<input;i++)
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
            cnt++;
            printf("%d\t",i);
            if (cnt%5==0)
            {
                printf("\n");
            }
            
        }
    }
    return 0;
}