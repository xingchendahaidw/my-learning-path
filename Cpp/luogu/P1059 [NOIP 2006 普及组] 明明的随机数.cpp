#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int a[MAXN]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    sort(a+1, a+n+1);
    int *end = unique(a+1, a+n+1);
    int cnt = end - (a+1);
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}