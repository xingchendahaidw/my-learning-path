#include <bits/stdc++.h>
using namespace std;//小数据组时可以用模拟

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, n;
    cin >> x >> n;
    int ans = 0;
    
    for (int i = 1; i <= n; i++)
    {
        // 周一到周五，累加里程
        if (x >= 1 && x <= 5)
            ans += 250;
        // 星期数后移一天，周日过了变周一
        x++;
        if (x == 8)
            x = 1;
    }
    
    cout << ans << endl;
    return 0;
}
