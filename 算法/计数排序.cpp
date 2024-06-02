#include <iostream>
#include <vector>

// ¼ÆÊıÅÅĞòº¯Êı
void countingSort(std::vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    std::vector<int> count(range), output(arr.size());

    for (int i = 0; i < arr.size(); ++i)
        ++count[arr[i] - min];

    for (int i = 1; i < count.size(); ++i)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - min] - 1] = arr[i];
        --count[arr[i] - min];
    }

    for (int i = 0; i < arr.size(); ++i)
        arr[i] = output[i];
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = { 4, 2, 2, 8, 3, 3, 1 };
    std::cout << "Unsorted array: ";
    printArray(arr);

    countingSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
