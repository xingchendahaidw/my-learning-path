#include <stdio.h>
#include <stdbool.h>

#define MAXN 100

int  graph[MAXN][MAXN];   // 邻接矩阵，graph[u][v]=1 表示 u-v 有边
bool visited[MAXN];
int  q[MAXN];             // 数组模拟队列
int  head = 0, tail = 0;  // [head, tail) 区间内的元素是队列内容

void bfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = false;

    visited[start] = true;   // 入队时就标记
    q[tail++] = start;       // 起点入队

    while (head < tail) {    // 队列非空
        int u = q[head++];   // 出队
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = true;
                q[tail++] = v;
            }
        }
    }
}

int main(void) {
    int n = 6;
    // 建图：0-1, 0-2, 1-3, 2-4, 3-5
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4},{3,5}};
    for (int i = 0; i < 5; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;   // 无向图
    }
    bfs(0, n);   // 输出：0 1 2 3 4 5
    return 0;
}