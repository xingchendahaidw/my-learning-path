#include<stdio.h>
int main()
{
    int i=0;
    int p= (int)&i;
    printf("%x\n",p);
    printf("%p\n",&i);
    printf("%lu\n",sizeof(int));
    printf("%lu\n",sizeof(&i));
    return 0;
}