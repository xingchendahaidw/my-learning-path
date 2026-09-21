#include<stdio.h>

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int cnt=0;
    int isPrime=1;
    int sum=0;
    int num=2;
    while (cnt<=n)
    {
       isPrime=1;
            for (int j=2; j<num; j++)
            {
                if (num%j==0)
                {
                    isPrime=0;
                    break;
                }
            }
            if(isPrime==1)
            {   
                cnt++;
                if (m<=cnt&&cnt<=n)
                {
                    sum+=num;
                } 
            }
        num++;
        }
    printf("%d",sum);
    return 0;
}