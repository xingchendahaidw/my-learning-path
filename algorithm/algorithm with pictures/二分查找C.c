#include <stdio.h>

// 二分查找函数
// 参数：arr 目标数组，length 数组长度，item 要查找的目标值
// 返回值：找到则返回对应索引，未找到则返回 -1（对应 Python 的 None）
int binary_search(int arr[], int length, int item) {
    // low 和 high 用于跟踪要在其中查找的列表部分
    int low = 0;
    int high = length - 1;

    // 只要范围没有缩小到只包含一个元素，就检查中间的元素
    while (low <= high) {
        // C语言整数除法会自动向下取整，等同于书中的 (low + high) / 2
        int mid = (low + high) / 2;
        int guess = arr[mid]; // 检查中间的元素

        if (guess == item) {
            return mid;       // 找到了元素，直接返回索引
        }
        if (guess > item) {
            high = mid - 1;   // 猜的数字大了，更新 high
        } else {
            low = mid + 1;    // 猜的数字小了，更新 low
        }
    }

    return -1;                // 没有指定的元素，返回 -1
}

int main() {
    // 定义并初始化数组
    int my_list[] = {1, 3, 5, 7, 9};
    
    // 利用 sizeof 自动计算数组长度
    int length = sizeof(my_list) / sizeof(my_list[0]);

    // 测试一：查找存在的元素 (对应 print binary_search(my_list, 3))
    int result1 = binary_search(my_list, length, 3);
    printf("查找 3 的结果 (索引): %d\n", result1); // 预期输出: 1

    // 测试二：查找不存在的元素 (对应 print binary_search(my_list, -1))
    int result2 = binary_search(my_list, length, -1);
    printf("查找 -1 的结果 (索引): %d\n", result2); // 预期输出: -1

    return 0;
}