#include <stdio.h>
#include <math.h>
int isPrime(int x);
int main()
{
    int primes[200];
    int cnt = 0;
    int num = 2;
    // 生成前200个素数
    while(cnt < 200)
     {
        if(isPrime(num)) {
            primes[cnt++] = num;
        }
        num++;
    }
    int n,m;
    scanf("%d %d", &n, &m);
    int sum = 0;
    for(int i = n-1; i <= m-1; i++)
    {
        sum += primes[i];
    }
    printf("%d\n", sum);
    return 0;
}
int isPrime(int x) 
{
    if (x < 2) 
    {
        return 0;
    }
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
        
    }
    return 1;
}