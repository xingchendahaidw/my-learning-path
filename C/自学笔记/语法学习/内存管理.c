#include<stdio.h>
#include <stdlib.h>
int main1() //malloc 与 free
{
    int n = 5;
    // 分配 n 个 int 大小的内存
    // malloc 返回 void*，需要转换成 int*
    int* arr = (int*)malloc(n * sizeof(int));

    // 注意：malloc 分配的内存内容是随机值（垃圾值）
    // 需要自己初始化
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    // 输出：0 10 20 30 40
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 用完之后释放内存
    free(arr);

    return 0;
}
int main2()//calloc
{
    int n = 5;

    // calloc(元素个数, 每个元素大小)
    // 分配并初始化为 0
    int* arr = (int*)calloc(n, sizeof(int));

    // 输出：0 0 0 0 0（已经初始化为 0 了）
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
int main3() 
{
    int arr[5];

    // memset：按字节设置内存值
    // 常用于将数组整体初始化为 0 或 -1
    memset(arr, 0, sizeof(arr));
    // 输出：0 0 0 0 0
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // memset 设为 -1 也是安全的（因为 -1 的每个字节都是 0xFF）
    memset(arr, -1, sizeof(arr));
    // 输出：-1 -1 -1 -1 -1
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // memcpy：复制内存
    int src[] = {10, 20, 30, 40, 50};
    int dest[5];
    memcpy(dest, src, sizeof(src));
    // 输出：10 20 30 40 50
    for (int i = 0; i < 5; i++) printf("%d ", dest[i]);
    printf("\n");

    return 0;
}