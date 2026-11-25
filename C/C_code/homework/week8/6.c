#include <stdio.h>

int main() {
    double a;
    long long result;
    scanf("%lf", &a);
    if (a >= 0) {
        result = (long long)(a + 0.5);
    } else {
        result = (long long)(a - 0.5);
    }
    printf("%lld\n", result);
    return 0;
}