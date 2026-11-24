#include <stdio.h>

int main() {
    int money;
    int actual_pay; 
    scanf("%d", &money);
    if (money < 500) {
        actual_pay = money * 9 / 10;
    } else if (money >= 500 && money < 1000) 
    {
        actual_pay = money * 8 / 10;
    } else 
    {
        actual_pay = money * 7 / 10;
    }
    printf("%d\n", actual_pay);
    return 0;
}