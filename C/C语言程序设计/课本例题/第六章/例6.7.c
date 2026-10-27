#include <stdlib.h>
#include <stdio.h>
#include<time.h>
int main(void)
{
    int magic;      // 计算机"想"的数
    int guess;      // 用户猜的数
    int counter=0;
    srand(time(NULL));
    magic = rand()%100+1; // 调用随机函数"想"一个数 magic
    do
    {
        printf("Please guess a magic number:");
        scanf("%d", &guess);  // 输入用户猜的数 guess
        if (guess > magic)
            printf("Wrong! Too big!\n");
        else if (guess < magic)
            printf("Wrong! Too small!\n");
        else
            printf("Right!\n");
    } while (guess!=magic);
    return 0;
}