#include<atdio.h>
int main()
{
    int sum=0;
    int num;
    int count=0;

    scanf("%d",&num);
    while(num!=-1)
    {
        sum=sum+num;
        count++;
        scanf("%d",&num);//一定要加防止死循环
    }
    printf("%f\n",sum/count*1.0);
    return 0;
}