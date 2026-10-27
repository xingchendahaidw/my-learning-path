#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int magic;      // 计算机"想"的数
    int guess;      // 用户猜的数

    magic = rand(); // 调用随机函数"想"一个数 magic
    printf("Please guess a magic number:");
    scanf("%d", &guess);  // 输入用户猜的数 guess

    if (guess > magic)
        printf("Wrong! Too big!\n");
    else if (guess < magic)
        printf("Wrong! Too small!\n");
    else
        printf("Right!\n");

    return 0;
}