#include<stdio.h>
int main ()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    //输入数值
    int arr[n][n];
    for (int x = 0; x <=n; x++)
    {
        for (int y = 0; y <=n; y++)
        {
            arr[a][b]=0;
        }
        
    }
    //初始化数组
    int dx[4]={0,+1,0,-1};
    int dy[4]={+1,0,-1,0};
    long long cnt=0;
    for (int  i=0; i <=n/2; i++)
    {
        int x=i,y=i-1;
        int len=n-2*i;
        for (int k = 0; k < 4; k++)
        {
            int step = (k == 0) ? len : (k == 3 ? len - 2 : len - 1);
            for (int l = 0; l <step ; l++)
            {
                x=x+dx[k];
                y=y+dy[k];
                cnt++;
                arr[x][y]=cnt;
            }
            
        }
        
    }
    //生成数组
    printf("%d",arr[a-1][b-1]);
    //输出,NND,忘-1了
    return 0;
}