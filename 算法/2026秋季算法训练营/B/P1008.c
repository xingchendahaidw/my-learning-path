#include <stdio.h>
#define MAXN 10000
int heap[MAXN];
int size;
void up(int u);
void down(int u);
void push(int x);
int pop();
int main()
{
    int n;
    scanf("%d", &n);
    size = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        push(x);
    }
    long long ans = 0;
    while(size >= 2)
    {
        int a = pop();
        int b = pop();
        int s = a + b;
        ans += s;
        push(s);
    }
    printf("%lld\n", ans);
    return 0;
}
void up(int u)
{
    while(u > 1 && heap[u] < heap[u/2])
    {
        int t = heap[u];
        heap[u] = heap[u/2];
        heap[u/2] = t;
        u /= 2;
    }
}
void down(int u)
{
    int t = u;
    if(u*2 <= size && heap[u*2] < heap[t]) t = u*2;
    if(u*2+1 <= size && heap[u*2+1] < heap[t]) t = u*2+1;
    if(t != u)
    {
        int tmp = heap[u];
        heap[u] = heap[t];
        heap[t] = tmp;
        down(t);
    }
}
void push(int x)
{
    heap[++size] = x;
    up(size);
}
int pop()
{
    int res = heap[1];
    heap[1] = heap[size--];
    down(1);
    return res;
}