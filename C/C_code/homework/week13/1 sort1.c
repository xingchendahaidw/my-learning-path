#include<stdio.h>
int main()
{
    //输入十个值
    int arr[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int index_min=0,index_max=9;
    for(int i=0;i<10;i++)
    {
        if(arr[index_min]>arr[i])
        {
            index_min=i;
        }
        if(arr[index_max]<arr[i])
        {
            index_max=i;
        }
    }
    int tmp;
    if(index_min!=0)
    {
        tmp=arr[0];
        arr[0]=arr[index_min];
        arr[index_min]=tmp;
    }
    if(index_max!=0)
    {
        tmp=arr[9];
        arr[9]=arr[index_max];
        arr[index_max]=tmp;
    }
    for(int i=0;i<10;i++)
    {
        if(i!=0)
        {
            printf(" ");
        }
        printf("%d",arr[i]);
    }
    return 0;
}