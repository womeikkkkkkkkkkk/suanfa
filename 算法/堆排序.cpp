#include <iostream>
#include <vector>

// �ѵ���������ά���ѵ�����
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // ��ʼ�����ֵΪ���ڵ�
    int left = 2 * i + 1; // ���ӽڵ�
    int right = 2 * i + 2; // ���ӽڵ�

    // ������ӽڵ���ڸ��ڵ�
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ӽڵ�������ֵ�ڵ�
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������ֵ���Ǹ��ڵ�
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // �ݹ�ص�����Ӱ�������
        heapify(arr, n, largest);
    }
}

// ��������
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // ��������
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // һ�����Ӷ���ȡ��Ԫ��
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]); // �ƶ���ǰ����ĩβ
        heapify(arr, i, 0); // ������
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
