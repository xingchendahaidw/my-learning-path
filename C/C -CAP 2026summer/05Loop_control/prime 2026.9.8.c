#include<stdio.h>
int main()
{
    int input;
    scanf("%d",&input);
    int i;
    int isPrime=1;
    for ( i=2; i<input; i++)
    {
        if (input%i==0)
        {
            isPrime=0;
            break;
        }
        
    }
    if (isPrime==0)
    {
        printf("%d不是质数\n",input);
    }else
    {
        printf("%d是质数\n",input);
    }
    return 0;
    
}