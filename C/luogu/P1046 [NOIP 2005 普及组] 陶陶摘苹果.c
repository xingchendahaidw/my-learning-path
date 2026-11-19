#include<stdio.h>
int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int n;
    scanf("%d",&n);
    n+=30;
    int cnt=0;
    for (int  i = 0; i <10; i++)
    {
        if(n>=arr[i])
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}