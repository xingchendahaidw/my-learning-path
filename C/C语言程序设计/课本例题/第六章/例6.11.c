#include<stdio.h>
int main()
{
    int days;
    printf("Input days");
    scanf("%d",&days);
    int x=1;
    do
    {
        x=(x+1)*2;
        days--;
    } while (days>1);
    printf("x=%d\n",x);
    return 0;
}
