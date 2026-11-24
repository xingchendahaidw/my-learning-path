#include<stdio.h>
#include<stdbool.h>

bool isLeap(int y);
int daysIn(int y,int m);
long long gLeaps(long long x);
static long long daysBeforeYear(int y);
long long dayOfYear(int y, int m, int d);

int main()
{
    int d, m, y;
    scanf("%d %d %d", &d, &m, &y);
    long long total = daysBeforeYear(y) + dayOfYear(y, m, d);

    if(y > 1582)
    {
        total -= 10;
    }else if(y == 1582)
    {
        if( (m > 10) || (m == 10 && d >=15) ){
            total -= 10;
        }
    }
    printf("%lld\n", total);
    return 0;
}

bool isLeap(int y)
{
    if (y<1582)
    {
        return y%4==0;
    }
    return (y%400==0)||(y%4==0&&y%100!=0);
}

int daysIn(int y,int m)
{
    if (m==2)
    {
        return isLeap(y)?29:28;
    }
    if (m==4||m==6||m==9||m==11)
    {
        return 30;
    }
    return 31;
}
long long gLeaps(long long x)
{
    return x/4-x/100+x/400;
}
static long long daysBeforeYear(int y)
{
    if(y <= 1582)
    {
        return 365LL*(y-1)+(y-1)/4;
    }else
    {
        return 577815LL + 365LL*(y-1583)+(gLeaps(y-1)-gLeaps(1582));
    }
}
long long dayOfYear(int y, int m, int d)
{
    long long sum = 0;
    for(int i=1; i<m; i++)
    {
        sum += daysIn(y, i);
    }
    sum += (d - 1); 
    return sum;
}