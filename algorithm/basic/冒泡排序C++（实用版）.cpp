#include <iostream>
#include <vector>
#include <string>

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& x : arr) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    std::vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(nums);
    printArray(nums);   // 11 12 22 25 34 64 90

    std::vector<double> ds = {3.14, 1.41, 2.71, 0.57};
    bubbleSort(ds);
    printArray(ds);     // 0.57 1.41 2.71 3.14

    std::vector<std::string> names = {"Tom", "Alice", "Bob", "Zoe"};
    bubbleSort(names);
    printArray(names);  // Alice Bob Tom Zoe

    return 0;
}
#include <iterator>
#include <utility>

template <typename Iterator>
void bubbleSort(Iterator begin, Iterator end) {
    if (begin == end) return;
    for (auto i = begin; i != std::prev(end); ++i) {
        bool swapped = false;
        for (auto j = begin; j != std::prev(end) - std::distance(begin, i); ++j) {
            if (*j > *(j + 1)) {
                std::swap(*j, *(j + 1));
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}