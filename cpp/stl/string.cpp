#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // 生成
    string str1 = "abcdef";
    string str2(str1);
    string str3(str1, 1, 4); //开始下标 长度
    string str4("abcdef", 3); // 前n
    string str5(5, 'a');
    string str6(str1, 3); //从3到结尾

    // 比较
    str1 > str2;
    str1.compare(str2); // ==0 >1 <-1

    // 增
    str1.push_back('a');
    str1.insert(str1.begin(), 'z');
    str1.append(str2);
    str1 += str3;

    // 删
    str1.erase(str1.begin());
    str3.clear();

    // 改
    str1.replace(0, 3, "a"); // 迭代器也行
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

    // 查
    str1.find("abc"); // 返回下标 -1表示没找到
    str1.find("e", 2); // 从2位置开始找
    str1.rfind("abc"); // 反向找
}