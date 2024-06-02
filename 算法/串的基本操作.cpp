#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* data;
    int length;

public:
    // 构造函数
    String(const char* str = "")
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // 拷贝构造函数
    String(const String& other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // 析构函数
    ~String()
    {
        delete[] data;
    }

    // 判空
    bool isEmpty() const
    {
        return length == 0;
    }

    // 获取字符串长度
    int getLength() const
    {
        return length;
    }

    // 连接字符串
    String concat(const String& other) const
    {
        char* newData = new char[length + other.length + 1];
        strcpy(newData, data);
        strcat(newData, other.data);
        String newString(newData);
        delete[] newData;
        return newString;
    }

    // 比较字符串
    int compare(const String& other) const
    {
        return strcmp(data, other.data);
    }

    // 查找子串
    int find(const String& substr) const
    {
        char* pos = strstr(data, substr.data);
        if (pos != nullptr)
        {
            return pos - data;
        }
        else
        {
            return -1;
        }
    }

    // 获取子串
    String substring(int pos, int len) const
    {
        if (pos < 0 || pos >= length || len < 0 || pos + len > length)
        {
            return String("");
        }
        char* subData = new char[len + 1];
        strncpy(subData, data + pos, len);
        subData[len] = '\0';
        String subString(subData);
        delete[] subData;
        return subString;
    }

    // 清空字符串
    void clear()
    {
        delete[] data;
        data = new char[1];
        data[0] = '\0';
        length = 0;
    }

    // 重载赋值运算符
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const String& str)
    {
        os << str.data;
        return os;
    }
};

int main()
{
    String str1("Hello");
    String str2("World");
    String str3 = str1.concat(str2);

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3 (concatenation of str1 and str2): " << str3 << endl;

    cout << "Length of str1: " << str1.getLength() << endl;
    cout << "Comparison of str1 and str2: " << str1.compare(str2) << endl;

    String substr("lo");
    cout << "Position of 'lo' in str1: " << str1.find(substr) << endl;

    String sub = str1.substring(1, 3);
    cout << "Substring of str1 from position 1 with length 3: " << sub << endl;

    str1.clear();
    cout << "str1 after clear: " << (str1.isEmpty() ? "empty" : str1) << endl;

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* data;
    int length;

public:
    // 构造函数
    String(const char* str = "")
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // 拷贝构造函数
    String(const String& other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // 析构函数
    ~String()
    {
        delete[] data;
    }

    // 判空
    bool isEmpty() const
    {
        return length == 0;
    }

    // 获取字符串长度
    int getLength() const
    {
        return length;
    }

    // 连接字符串
    String concat(const String& other) const
    {
        char* newData = new char[length + other.length + 1];
        strcpy(newData, data);
        strcat(newData, other.data);
        String newString(newData);
        delete[] newData;
        return newString;
    }

    // 比较字符串
    int compare(const String& other) const
    {
        return strcmp(data, other.data);
    }

    // 查找子串
    int find(const String& substr) const
    {
        char* pos = strstr(data, substr.data);
        if (pos != nullptr)
        {
            return pos - data;
        }
        else
        {
            return -1;
        }
    }

    // 获取子串
    String substring(int pos, int len) const
    {
        if (pos < 0 || pos >= length || len < 0 || pos + len > length)
        {
            return String("");
        }
        char* subData = new char[len + 1];
        strncpy(subData, data + pos, len);
        subData[len] = '\0';
        String subString(subData);
        delete[] subData;
        return subString;
    }

    // 清空字符串
    void clear()
    {
        delete[] data;
        data = new char[1];
        data[0] = '\0';
        length = 0;
    }

    // 重载赋值运算符
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const String& str)
    {
        os << str.data;
        return os;
    }
};

int main()
{
    String str1("Hello");
    String str2("World");
    String str3 = str1.concat(str2);

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3 (concatenation of str1 and str2): " << str3 << endl;

    cout << "Length of str1: " << str1.getLength() << endl;
    cout << "Comparison of str1 and str2: " << str1.compare(str2) << endl;

    String substr("lo");
    cout << "Position of 'lo' in str1: " << str1.find(substr) << endl;

    String sub = str1.substring(1, 3);
    cout << "Substring of str1 from position 1 with length 3: " << sub << endl;

    str1.clear();
    cout << "str1 after clear: " << (str1.isEmpty() ? "empty" : str1) << endl;

    return 0;
}
