#include <iostream>
#include <vector>

// ��ѡ��������
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // ���赱ǰԪ��Ϊ��Сֵ

        // �ҵ�δ���򲿷ֵ���Сֵ
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // ������Сֵ�͵�ǰԪ��
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
