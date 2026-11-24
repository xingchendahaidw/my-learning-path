#include <stdio.h>
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        // m:男人，w:女人，c:小孩
        // 约束：m + w + c = x，3*m + 2*w + c = y
        // 消元：2*m + w = y - x
        for (int m = 0; m <= x; m++) {
            for (int w = 0; w <= x; w++) {
                int c = x - m - w;
                if (c >= 0 && 3*m + 2*w + c == y) {
                    printf("%d %d %d\n", m, w, c);
                }
            }
        }
    }
    return 0;
}