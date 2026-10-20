#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);   // 用 std::swap 代替 temp
            }
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int x : arr) {                          // 范围 for
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "排序前: ";
    printArray(arr);

    bubbleSort(arr);

    std::cout << "排序后: ";
    printArray(arr);

    return 0;
}
void bubbleSortOptimized(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;   // 已有序，提前结束
    }
}
