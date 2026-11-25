#include <stdio.h>
#define maxsize 100000
int main() 
{
    int i,n,a[maxsize],N,index,k,ans;
    scanf("%d", &N);
    for (int j = 0; j < N; j++) {
        scanf("%d", &n);  // 有 n 个数据
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);  // 读入 a[i]
        }
        for(i=0;i<n;i++)
        {
           int cnt = 0;
            // 遍历全数组统计当前元素出现总次数，避免漏判前方重复
            for (int j = 0; j < n; j++)
            {
                if (a[i] == a[j])
                    cnt++;
            }
            if (cnt == 1)
            {
                ans = a[i];
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}