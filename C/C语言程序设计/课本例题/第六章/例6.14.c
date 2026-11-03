#include<stdio.h>//Çî¾Ù·¨
#include<stdlib.h>
int main()
{
    for (int x = 1;; x++)
    {
        if (x%5==1&&x%6==5&&x%7==4&&x%11==10)
        {
            printf("x=%d\n",x);
            break;
        }
    }
    return 0;
}
int main()
{
    for (int x = 1;; x++)
    {
        if (x%5==1&&x%6==5&&x%7==4&&x%11==10)
        {
            printf("x=%d\n",x);
            exit(0);
        }
    }
    return 0;
}
int main()
{
    int find=0;
    for (int x = 1;!find; x++)
    {
        if (x%5==1&&x%6==5&&x%7==4&&x%11==10)
        {
            printf("x=%d\n",x);
            find=1;
        }
    }
    return 0;
}