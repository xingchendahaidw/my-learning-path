#include <stdlib.h>
#include <stdio.h>
#include<time.h>
int main(void)
{
    int magic;      // 计算机"想"的数
    int guess;      // 用户猜的数
    int counter=0;
    int ret;
    srand(time(NULL));
    magic = rand()%100+1; // 调用随机函数"想"一个数 magic
    do
    {
        
        ret=scanf("%d", &guess);  // 输入用户猜的数 guess
        while (ret!=1)
        {
            while (getchar()!='\n')
            {
                printf("Please guess a magic number:");
                ret=scanf("%d", &guess);
            }
        }
        counter++;
        if (guess > magic)
            printf("Wrong! Too big!\n");
        else if (guess < magic)
            printf("Wrong! Too small!\n");
        else
            printf("Right!\n");
    } while (guess!=magic&&counter<10);
    return 0;
}