#include <stdio.h>
#include <stdlib.h>

// 1. 定义结构体，用来把“数值”和“原始下标”绑定在一起
typedef struct {
    int val; // 数组元素的值
    int idx; // 元素在原数组中的下标 (1-based)
} Item;

// 2. 编写 qsort 所需的比较函数
int cmp(const void* a, const void* b) {
    Item* ia = (Item*)a;
    Item* ib = (Item*)b;
    if (ia->val != ib->val) {
        return ia->val - ib->val; // 如果数值不同，按数值升序排列
    }
    return ia->idx - ib->idx;     // 如果数值相同，按原始下标升序排列
}

int main() {
    int n, k;
    // 3. 读取 n 和 k
    if (scanf("%d %d", &n, &k) != 2) return 0;

    // 4. 动态分配大小为 n 的结构体数组
    Item* items = (Item*)malloc(n * sizeof(Item));
    
    // 5. 读取数组，并记录每个元素的原始下标
    for (int i = 0; i < n; ++i) {
        scanf("%d", &items[i].val);
        items[i].idx = i + 1; // 下标从 1 开始
    }

    // 6. 对结构体数组进行排序
    qsort(items, n, sizeof(Item), cmp);

    // 7. 准备一个答案数组，用于按原顺序存储结果
    int* ans = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) {
        ans[i] = -1; // 默认全部初始化为 -1
    }

    // 8. 遍历排序后的数组，寻找满足条件的区间
    int i = 0;
    while (i < n) {
        int j = i;
        // 8.1 找到与 items[i] 数值相同的所有元素的边界（[i, j-1] 都是同一个值）
        while (j < n && items[j].val == items[i].val) {
            j++;
        }
        
        // 8.2 遍历当前这个值的所有出现位置
        for (int p = i; p < j; ++p) {
            // 8.3 如果当前元素前面（包含自己）已经有至少 k 个相同的元素
            // p - i 表示当前元素是这一组相同元素中的第几个（从 0 开始数）
            if (p - i >= k - 1) {
                int left_idx = p - k + 1; // 往前数 k 个元素的数组位置
                // 8.4 记录答案：当前元素原下标对应的左端点，就是往前数第 k 个元素的原下标
                ans[items[p].idx] = items[left_idx].idx; 
            }
        }
        i = j; // 8.5 跳过当前数值的所有元素，处理下一个不同的数值
    }

    // 9. 按 1 到 n 的原始顺序输出答案
    for (int p = 1; p <= n; ++p) {
        printf("%d\n", ans[p]);
    }

    // 10. 释放动态分配的内存
    free(items);
    free(ans);
    
    return 0;
}