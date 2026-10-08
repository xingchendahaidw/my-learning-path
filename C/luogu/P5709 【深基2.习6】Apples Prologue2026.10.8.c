#include<stdio.h>
int main()
{
    int num_app;
    int time_1app;
    int time;
    scanf("%d %d %d",&num_app,&time_1app,&time);
    int num_applft;
    if (time_1app!=0)
    {
        if (time%time_1app==0)
        {
            num_applft=num_app-time/time_1app;
        } else
        {
            num_applft=num_app-(time/time_1app+1);
        }
        
    } else num_applft=0;
    if (num_applft<=0)
    {
        num_applft=0;
    }
    printf("%d",num_applft);
    return 0;
}