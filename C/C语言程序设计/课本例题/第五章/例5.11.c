#include<stdio.h>
int main()
{
    short x=12,y=8;
    printf("%5hd%5hd%5hd\n",!x,x||y,x&&y);
    printf("%5hu%5hd%5hd\n",~x,x|y,x&y);
    printf("%5hd%5hd%5hd\n\n",~x,x|y,x&y);
    return 0;
}