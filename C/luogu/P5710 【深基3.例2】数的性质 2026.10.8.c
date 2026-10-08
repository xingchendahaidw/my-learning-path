#include<stdio.h>
int main()
{
    int x;
    int isEven=0;
    int incuded=0;
    scanf("%d",&x);

    if (x%2==0)
    {
        isEven=1;
    }
    if (x>4&&x<=12)
    {
        incuded=1;
    }

    printf("%d %d %d %d",isEven&incuded,isEven|incuded,isEven^incuded,!isEven&!incuded);
    
    return 0;
}