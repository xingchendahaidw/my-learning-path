#include <stdio.h>
int main() {
    int n, i;
    scanf("%d", &n);  // 有n组数据
    for (i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        int first, second;
        int x, j;

        // 读入第一个数
        scanf("%d", &x);
        first = x;

        // 读入第二个数，按绝对值规则排好前两名
        scanf("%d", &x);
        int af = first < 0 ? -first : first;
        int ax = x < 0 ? -x : x;
        if (ax > af || (ax == af && x > first)) {
            second = first;
            first = x;
        } else {
            second = x;
        }

        // 遍历剩余数字，维护绝对值前两名
        for (j = 2; j < m; j++) {
            scanf("%d", &x);
            ax = x < 0 ? -x : x;
            af = first < 0 ? -first : first;
            int as = second < 0 ? -second : second;

            // 比第一名绝对值更大，或绝对值相等但数值更大
            if (ax > af || (ax == af && x > first)) {
                second = first;
                first = x;
            }
            // 比第二名绝对值更大，或绝对值相等但数值更大
            else if (ax > as || (ax == as && x > second)) {
                second = x;
            }
        }

        // 最终按「原值从大到小」排序后输出
        if (first < second) {
            int temp = first;
            first = second;
            second = temp;
        }
        printf("%d %d\n", first, second);
    }
    return 0;
}
