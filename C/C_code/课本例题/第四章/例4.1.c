#include<stdio.h>
int main()
{
    char ch;
    printf("Press a key and then press Enter:");
    ch=getchar();
    ch=ch+32;
    putchar(ch);
    putchar('\n');
    return 0;
}