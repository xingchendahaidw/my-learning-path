#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void)
{
    int magic=0;      // 计算机"想"的数
    int guess=0;      // 用户猜的数
    int counter=0;
    int ret;
    char reply;
    srand(time(NULL));
    magic = rand()%100+1; // 调用随机函数"想"一个数 magic
    do
    {
        counter=0;
        magic=rand()%100+1;
        do
        {
        printf("Please guess a magic number:");
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
        
        printf("counter=%d\n",counter);
        printf("Do you want to continue (Y/N or y/n)?");
        scanf("%c",&reply);
    } while (reply=='Y'||reply=='y');
    return 0;
}