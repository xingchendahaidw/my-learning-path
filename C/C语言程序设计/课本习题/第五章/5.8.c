#include<stdio.h>
//原版，糖了
int main ()
{
    char c;
    scanf("%c",&c);
    //全部输入
    int kind=5;
    if (c==' ')
    {
        kind=1;
    }
    if (c>='0'&&c<='9')//应该用else if
    {
        kind=2;
    }
    if (c>='A'&&c<='Z')
    {
        kind=3;
    }
    if (c>='a'&&c<='z')
    {
        kind=4;
    }
    switch (kind)
    {
    case 1:
        printf("是空格");
        break;
    case 2:
        printf("是数字");
        break;
    case 3:
        printf("是大写字母");
        break;
    case 4:
        printf("是小写字母");
        break;
    case 5:
        printf("是其他字符");
        break;
    }
    return 0;
    
}
//简洁版
#include <stdio.h>
int main()
{
    char ch;
    printf("请输入一个字符：");
    scanf("%c", &ch);

    if (ch >= '0' && ch <= '9')
    {
        printf("这是数字字符\n");
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("这是大写英文字母\n");
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        printf("这是小写英文字母\n");
    }
    else if (ch == ' ')
    {
        printf("这是空格\n");
    }
    else
    {
        printf("这是其他字符\n");
    }

    return 0;
}
