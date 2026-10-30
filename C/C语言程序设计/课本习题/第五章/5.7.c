#include<stdio.h>
//原稿：过于复杂，并且没有单一出口
int main()
{
    char c;
    scanf("%c",&c);
    if (c>=65&&c<=90)
    {
        c+=32;
        printf("%c",c);
    }else
    {
        if (c>=97&&c<=122)
        {
            c-=32;
            printf("%c %d",c,c);
        }else
        {
            printf("%c %d",c);
        }
    }
    return 0;
}
//AI改后
int main()
{
    char c;
    scanf("%c",&c);
    if (c>=65&&c<=90)
    {
        c+=32;
    }else if (c>=97&&c<=122)
    {
        c-=32;
    }
    // 统一输出：转换后的字符 + ASCII码，所有情况共用一句
    printf("%c %d",c,c);
    return 0;
}
//AI版本1
int main(void)
{
    char ch;
    printf("请输入一个字符：");
    scanf("%c", &ch);

    if(ch >= 'A' && ch <= 'Z')//直接运用''，避免查询ASC码表
    {
        // 大写转小写，+32
        ch = ch + 32;
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        // 小写转大写，-32
        ch = ch - 32;
    }
    // 不是字母，什么都不做，保持原样

    printf("转换后的字符：%c，ASCII码：%d\n", ch, ch);
    return 0;
}
//AI版本2
#include <stdio.h>
#include <ctype.h>//字符处理函数库
int main(void)
{
    char ch;
    printf("请输入一个字符：");
    scanf("%c", &ch);

    if(isupper(ch))
    {
        ch = tolower(ch);
    }
    else if(islower(ch))
    {
        ch = toupper(ch);
    }

    printf("转换后的字符：%c，ASCII码：%d\n", ch, ch);
    return 0;
}
//

