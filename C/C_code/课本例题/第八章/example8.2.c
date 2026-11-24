#include<stdio.h>
//数组下标越界示例
int main(void)
{
    int a = 1, c = 2, b[5] = {0}, i;
    printf("%p, %p, %p\n", b, &c, &a);  // 用%p格式打印数组、变量的内存地址
    for (i = 0; i <= 8; i++)             // 故意让下标越界访问
    {
        b[i] = i;
        printf("%d ", b[i]);
    }
    printf("\nc = %d, a = %d, i = %d\n", c, a, i);
    return 0;
}
