#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void selectionSort(int arr[],int n)
{
    int index,min;
    for(int i=0;i<n-1;i++)
    {
        index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[index])
            {
                index=j;
            }
        }
        int tmp;
        if(index!=i)
        {
            tmp=arr[i];
            arr[i]=arr[index];
            arr[index]=tmp;
        }
    }
}
void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[6];
    int n=sizeof(arr)/sizeof(arr[0]);

    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    printArr(arr,n);
    printf("\n");
    selectionSort(arr,n);
    printArr(arr,n);
    return 0;
}