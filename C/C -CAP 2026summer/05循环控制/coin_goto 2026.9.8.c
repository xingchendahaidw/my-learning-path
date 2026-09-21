#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int one,two,five;
    for(one=1;one<x*10;one++)
    {
        for (two= 0;two<x*10/2;two++)
        {
            for (five=1;five<x*10/5;five++)
            {
                if (one*1+two*2+five*5==x*10)
                {
                    printf("可以用%d个1角%d个2角和%d个5角获得%d元",one,two,five,x);
                    goto out;
                }   
            }
        }
    }
    out:
    return 0;
}