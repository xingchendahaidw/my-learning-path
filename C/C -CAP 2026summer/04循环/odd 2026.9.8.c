#include<stdio.h>
int main()
{
    int num;
    int odd_num=0;
    int even_num=0;
    printf("请输入一序列数");
    scanf("%d",&num);
    do
    {
        if(num%2==0)
        {
            even_num++;
        } else
        {
            odd_num++;
        }
        scanf("%d",&num);
    } while (num!=-1);
    printf("%d %d",odd_num,even_num);
    return 0;
    
}