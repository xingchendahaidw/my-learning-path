#include<stdio.h>
void printer(int arr[],int n);
void bubbleSort(int arr[],int n);
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    return 0;
}
void printer(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            printf(" ");
        }
        printf("%d",arr[i]);
    }
    printf("\n");
}
void bubbleSort(int arr[],int n)
{
    int tmp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
        printer(arr,n);
    }
}