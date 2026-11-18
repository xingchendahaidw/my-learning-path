#include <stdio.h>
#include <stdlib.h>
int main1() //指针的基本用法
{
    int a = 42;

    // &a 取变量 a 的内存地址
    // int* p 声明一个指向 int 的指针变量 p
    int* p = &a;

    // p 存的是地址，打印出来是一串数字
    printf("a 的地址：%p\n", (void*)p);
    // *p 解引用：通过地址取值
    // 输出：42
    printf("*p = %d\n", *p);

    // 通过指针修改 a 的值
    *p = 100;
    // a 变成了 100！
    printf("a = %d\n", a);

    // & 和 * 是反操作：先取地址再解引用，回到原值
    printf("*(&a) = %d\n", *(&a)); // 100

    return 0;
}

// 值传递：改不了原变量
void tryChange(int x) {
    x = 999;
}

// 指针传递：传的是地址，能改
void realChange(int* p) {
    *p = 999;
}

// 经典用法：交换两个变量的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main2() //指针传值
{
    int a = 10;

    tryChange(a);
    // 输出：10（没变）
    printf("tryChange 后：a = %d\n", a);

    realChange(&a);
    // 输出：999（变了！）
    printf("realChange 后：a = %d\n", a);

    int x = 1, y = 2;
    swap(&x, &y);
    // 输出：x = 2, y = 1
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
int main3() //指针用于遍历
{
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;  // p 指向数组第一个元素

    // p 指向 arr[0]
    printf("*p     = %d\n", *p);       // 10
    // p+1 指向 arr[1]（地址跳过 4 字节，即一个 int）
    printf("*(p+1) = %d\n", *(p+1));   // 20
    // p+2 指向 arr[2]
    printf("*(p+2) = %d\n", *(p+2));   // 30

    // 用指针遍历数组
    printf("遍历：");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
    // 输出：10 20 30 40 50

    // 也可以用 p++ 移动指针
    printf("p++ 遍历：");
    p = arr;  // 重新指向开头
    while (p < arr + 5) {
        printf("%d ", *p);
        p++;  // 指针后移一个元素
    }
    printf("\n");
    // 输出：10 20 30 40 50

    return 0;
}

int main4() //指针的数组，常用字符串数组
{
    int a = 10, b = 20, c = 30;

    // 指针的数组：3 个元素，每个是 int*
    int* arr[3];
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    for (int i = 0; i < 3; i++) {
        printf("*arr[%d] = %d\n", i, *arr[i]);
    }
    // 输出：
    // *arr[0] = 10
    // *arr[1] = 20
    // *arr[2] = 30

    // 最常见的用途：字符串数组
    // 每个元素是 char*，指向一个字符串常量
    char* names[] = {"Alice", "Bob", "Charlie"};
    for (int i = 0; i < 3; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}

int main5() //数组的指针
{int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    // 数组的指针：p 指向一个 int[3] 数组    
    // matrix 的每一行就是一个 int[3]    
    int (*p)[3] = matrix;
    // p[0] 是第一行，p[1] 是第二行    
    printf("p[0][2] = %d\n", p[0][2]); // 3    
    printf("p[1][1] = %d\n", p[1][1]); // 5
    // p+1 跳过一整行（3 个 int = 12 字节）    
    int (*row2)[3] = p + 1;    
    printf("第二行第一个元素：%d\n", (*row2)[0]); // 4
    return 0;
}

int main6() //指向指针的指针
{
    int a = 42;
    int* p = &a;    // p 指向 a
    int** pp = &p;  // pp 指向 p

    printf("a   = %d\n", a);       // 42
    printf("*p  = %d\n", *p);      // 42（解引用一次：从 p 到 a）
    printf("**pp = %d\n", **pp);   // 42（解引用两次：从 pp 到 p，再到 a）

    // 通过 pp 修改 a
    **pp = 100;
    printf("a = %d\n", a); // 100

    return 0;
}

// 在函数里让一个指针指向新分配的内存
void allocate(int** pp, int size) {
    // *pp 就是外面的 arr
    *pp = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*pp)[i] = i * 10;
    }
}

int main()//用二级指针指针修改指针
{
    int* arr = NULL;

    // 传 &arr，让函数修改 arr 的指向
    allocate(&arr, 5);

    // 输出：0 10 20 30 40
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}