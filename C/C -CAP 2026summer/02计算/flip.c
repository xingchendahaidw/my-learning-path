#include<stdio.h>
int main()
{
    int num=0;

    scanf("%d",&num);
    printf("%d%d%d",num%10,num/10-(num/100*10),num/100);
    
    return 0;
}