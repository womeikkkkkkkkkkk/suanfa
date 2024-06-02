#include <iostream>
#include <vector>

// 堆调整函数，维护堆的性质
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // 初始化最大值为根节点
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于最大值节点
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // 递归地调整受影响的子树
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // 一个个从堆中取出元素
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]); // 移动当前根到末尾
        heapify(arr, i, 0); // 调整堆
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    std::cout << "Unsorted array: ";
    printArray(arr);

    heapSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
