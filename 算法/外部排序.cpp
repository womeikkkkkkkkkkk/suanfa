#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// 将文件内容读入数组
void readFile(const std::string& filename, std::vector<int>& arr) {
    std::ifstream infile(filename);
    int num;
    while (infile >> num) {
        arr.push_back(num);
    }
    infile.close();
}

// 将数组内容写入文件
void writeFile(const std::string& filename, const std::vector<int>& arr) {
    std::ofstream outfile(filename);
    for (int num : arr) {
        outfile << num << " ";
    }
    outfile.close();
}

// 外部排序函数
void externalSort(const std::string& inputFile, const std::string& outputFile) {
    std::vector<int> arr;
    readFile(inputFile, arr);

    std::sort(arr.begin(), arr.end());

    writeFile(outputFile, arr);
}

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";

    externalSort(inputFile, outputFile);

    std::cout << "Sorted data written to " << outputFile << std::endl;

    return 0;
}
