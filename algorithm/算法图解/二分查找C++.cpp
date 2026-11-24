#include <iostream>
#include <vector>
// 二分查找函数
// 参数：arr 目标数组（常量引用，避免拷贝），item 要查找的目标值
// 返回值：找到则返回对应索引，未找到则返回 -1
int binary_search(const std::vector<int>& arr, int item) 
{
    // low 和 high 用于跟踪要在其中查找的列表部分
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1; // 注意类型转换，避免 size_t 无符号整数带来的隐患

    // 只要范围没有缩小到只包含一个元素，就检查中间的元素
    while (low <= high) 
    {
        // 计算中间索引。使用 low + (high - low) / 2 可以防止 (low + high) 溢出
        int mid = low + (high - low) / 2;
        int guess = arr[mid]; // 检查中间的元素

        if (guess == item) 
        {
            return mid;       // 找到了元素，直接返回索引
        }
        if (guess > item) 
        {
            high = mid - 1;   // 猜的数字大了，更新 high
        } else 
        {
            low = mid + 1;    // 猜的数字小了，更新 low
        }
    }

    return -1;                // 没有指定的元素，返回 -1
}

int main() 
{
    // 使用初始化列表直接定义 vector，无需再单独计算长度
    std::vector<int> my_list = {1, 3, 5, 7, 9};

    // 测试一：查找存在的元素 (对应 print binary_search(my_list, 3))
    int result1 = binary_search(my_list, 3);
    std::cout << "查找 3 的结果 (索引): " << result1 << std::endl; // 预期输出: 1

    // 测试二：查找不存在的元素 (对应 print binary_search(my_list, -1))
    int result2 = binary_search(my_list, -1);
    std::cout << "查找 -1 的结果 (索引): " << result2 << std::endl; // 预期输出: -1

    return 0;
}