#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int a, b;
} Flight;

Flight dom[MAXN], intl[MAXN];
int f_dom[MAXN], f_int[MAXN];
int n, m1, m2;

// 排序比较函数
int cmp(const void *a, const void *b) {
    Flight *fa = (Flight *)a;
    Flight *fb = (Flight *)b;
    if (fa->a != fb->a) return fa->a - fb->a;
    return fa->b - fb->b;
}
// ---------- 手写小根堆：维护空闲廊桥编号 ----------
int free_heap[MAXN];
int free_size = 0;

void push_free(int val) {
    free_heap[free_size++] = val;
    int i = free_size - 1;
    while (i > 0 && free_heap[(i - 1) / 2] > free_heap[i]) {
        int tmp = free_heap[i];
        free_heap[i] = free_heap[(i - 1) / 2];
        free_heap[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}
void pop_free() {
    if (free_size == 0) return;
    free_heap[0] = free_heap[--free_size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, min_idx = i;
        if (l < free_size && free_heap[l] < free_heap[min_idx]) min_idx = l;
        if (r < free_size && free_heap[r] < free_heap[min_idx]) min_idx = r;
        if (min_idx == i) break;
        int tmp = free_heap[i];
        free_heap[i] = free_heap[min_idx];
        free_heap[min_idx] = tmp;
        i = min_idx;
    }
}
int top_free() { return free_heap[0]; }
int empty_free() { return free_size == 0; }
// ---------- 手写小根堆：维护正在占用的廊桥 ----------
typedef struct {
    int end_time, id;
} UsedNode;
UsedNode used_heap[MAXN];
int used_size = 0;
void push_used(int end_time, int id) {
    used_heap[used_size].end_time = end_time;
    used_heap[used_size].id = id;
    int i = used_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (used_heap[p].end_time < used_heap[i].end_time ||
           (used_heap[p].end_time == used_heap[i].end_time && used_heap[p].id <= used_heap[i].id)) {
            break;
        }
        UsedNode tmp = used_heap[i];
        used_heap[i] = used_heap[p];
        used_heap[p] = tmp;
        i = p;
    }
}
void pop_used() {
    if (used_size == 0) return;
    used_heap[0] = used_heap[--used_size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, min_idx = i;
        if (l < used_size && (used_heap[l].end_time < used_heap[min_idx].end_time ||
           (used_heap[l].end_time == used_heap[min_idx].end_time && used_heap[l].id < used_heap[min_idx].id))) {
            min_idx = l;
        }
        if (r < used_size && (used_heap[r].end_time < used_heap[min_idx].end_time ||
           (used_heap[r].end_time == used_heap[min_idx].end_time && used_heap[r].id < used_heap[min_idx].id))) {
            min_idx = r;
        }
        if (min_idx == i) break;
        UsedNode tmp = used_heap[i];
        used_heap[i] = used_heap[min_idx];
        used_heap[min_idx] = tmp;
        i = min_idx;
    }
}
UsedNode top_used() { return used_heap[0]; }
int empty_used() { return used_size == 0; }

// ---------- 核心模拟计算函数 ----------
void calc(Flight *flights, int m, int max_n, int *pre) {
    qsort(flights, m, sizeof(Flight), cmp);

    free_size = 0;
    used_size = 0;

    // 初始化提供 max_n 个廊桥
    for (int i = 1; i <= max_n; ++i) {
        push_free(i);
    }

    int *cnt = (int *)calloc(max_n + 1, sizeof(int));

    for (int i = 0; i < m; ++i) {
        // 释放空闲
        while (!empty_used() && top_used().end_time <= flights[i].a) {
            push_free(top_used().id);
            pop_used();
        }

        // 分配廊桥
        if (!empty_free()) {
            int id = top_free();
            pop_free();
            push_used(flights[i].b, id);
            if (id <= max_n) {
                cnt[id]++;
            }
        }
    }

    pre[0] = 0;
    for (int i = 1; i <= max_n; ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    free(cnt);
}
int main() {
    if (scanf("%d %d %d", &n, &m1, &m2) != 3) return 0;
    
    for (int i = 0; i < m1; ++i) {
        scanf("%d %d", &dom[i].a, &dom[i].b);
    }
    for (int i = 0; i < m2; ++i) {
        scanf("%d %d", &intl[i].a, &intl[i].b);
    }

    calc(dom, m1, n, f_dom);
    calc(intl, m2, n, f_int);

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int sum = f_dom[i] + f_int[n - i];
        if (sum > ans) ans = sum;
    }

    printf("%d\n", ans);
    return 0;
}