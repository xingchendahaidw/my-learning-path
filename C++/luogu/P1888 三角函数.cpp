#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    
    sort(a,a+3);
    int x,y,tmp;
    x=a[0];
    y=a[2];
    while (y!=0)
    {
        tmp=x%y;
        x=y;
        y=tmp; 
    }
    cout<<a[0]/x<<'/'<<a[2]/x<<endl;
    return 0;
}