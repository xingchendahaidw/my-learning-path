#include<stdio.h>
int isPrime(int x);
int main()
{
    int input=0;
    scanf("%d",input);
    int ori=imput;
    printf("%d=",input);
    while (isPrime(input)!=1)
    {
        for (int i = ; i < input; i++)
        {
            /* code */
        }
        
    }
    
    return 0;
}
int isPrime(int x)
{
    int is_p=1;
    for (int  i = 2; i < x; i++)
    {
        if (x%i==0)
        {
            is_p=0;
            break;
        }   
    }
    return is_p;
}