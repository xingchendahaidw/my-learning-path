#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Flight {
    int a, b; // 到达时间，离开时间
};

// 计算在拥有 max_n 个廊桥时，能停靠的航班数前缀和
vector<int> calc(vector<Flight>& flights, int max_n) {
    // 按到达时间升序排序
    sort(flights.begin(), flights.end(), [](const Flight& x, const Flight& y) {
        return x.a < y.a;
    });

    priority_queue<int, vector<int>, greater<int>> free_q;
    for (int i = 1; i <= max_n; ++i) {
        free_q.push(i);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used_q;
    
    // 记录每个廊桥被使用的次数
    vector<int> cnt(max_n + 1, 0);
    for (const auto& f : flights) {
        // 释放所有已经离开的廊桥
        while (!used_q.empty() && used_q.top().first <= f.a) {
            free_q.push(used_q.top().second);
            used_q.pop();
        }

        // 如果有空闲廊桥，则分配
        if (!free_q.empty()) {
            int id = free_q.top();
            free_q.pop();
            used_q.push({f.b, id});
            if (id <= max_n) {
                cnt[id]++;
            }
        }
    }

    // 计算前缀和
    vector<int> pre(max_n + 1, 0);
    for (int i = 1; i <= max_n; ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    return pre;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m1, m2;
    if (!(cin >> n >> m1 >> m2)) return 0;

    vector<Flight> dom(m1), intl(m2);
    for (int i = 0; i < m1; ++i) cin >> dom[i].a >> dom[i].b;
    for (int i = 0; i < m2; ++i) cin >> intl[i].a >> intl[i].b;

    // 分别计算国内和国际的前缀和
    vector<int> f_dom = calc(dom, n);
    vector<int> f_int = calc(intl, n);

    int ans = 0;
    // 枚举分配给国内区的廊桥数量 i
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, f_dom[i] + f_int[n - i]);
    }

    cout << ans << "\n";
    return 0;
}