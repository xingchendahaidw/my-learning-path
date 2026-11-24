#include<stdio.h>
int main()
{
    int cnt=0;
    for (int  i = 1; i <=10000; i++)
    {
        if (i%13==0&&i%17==0)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}