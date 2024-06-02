#include <iostream>
#include <vector>

// 简单选择排序函数
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // 假设当前元素为最小值

        // 找到未排序部分的最小值
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // 交换最小值和当前元素
        std::swap(arr[i], arr[minIndex]);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = { 64, 25, 12, 22, 11 };
    std::cout << "Unsorted array: ";
    printArray(arr);

    selectionSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
