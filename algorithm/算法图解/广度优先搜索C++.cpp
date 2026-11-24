#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;   // 邻接表：adj[u] 存 u 的所有邻居
vector<bool> visited;

void bfs(int start) {
    queue<int> q;

    visited[start] = true;   // 入队前标记
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();             // 出队
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 6;
    adj.assign(n, {});
    visited.assign(n, false);

    auto addEdge = [&](int u, int v) {   // 无向图
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    addEdge(0,1); addEdge(0,2);
    addEdge(1,3); addEdge(2,4);
    addEdge(3,5);

    bfs(0);   // 输出：0 1 2 3 4 5
    cout << endl;
    return 0;
}
//两种变式
//1）按层处理：一次处理完整个队列长度，可求"最少步数"。
int level = 0;
while (!q.empty()) {
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!visited[v]) { visited[v] = true; q.push(v); }
    }
    level++;   // 每处理完一层 +1
}
//2）记录最短路距离：把 visited 换成 dist 数组，dist[v] = dist[u] + 1。因为 BFS 按层推进，节点第一次被访问时的距离就是最短距离（仅限无权图，带权图要用 Dijkstra）。