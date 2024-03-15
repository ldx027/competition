#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // 创建
    std::vector<int> vec1;
    std::vector<int> vec2(vec1);
    std::vector<int> vec3(100); // n = 100
    std::vector<int> vec4(10, 3); // 10 个 3
    std::vector<int> vec5{1, 2, 3};
    std::vector<std::vector<int>> vec6(5, std::vector<int>(6));
    std::vector<int> vec;

    // 常用操作
    vec.empty(); // 判空
    vec.size();
    vec.push_back(1);
    vec.pop_back();
    vec[0];
    vec.back();
    vec.front();
    vec1 = vec;
    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec1 == vec2;
    vec1 > vec2;
    vec.resize(11, 0); //调整为11个元素 不足的用0填充

    // 迭代器
    // auto it = vec.begin();
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it << std::endl;
        it++;
    }

    it = vec.begin();
    it = vec.insert(it, 3, 5); // 在it前插入3个5 返回新添加的第一个元素的迭代器

    auto it1 = vec.begin();
    auto it2 = vec.begin();
    for (int i = 0; i < 3; i++) it2++;
    it1 = vec.erase(it1); // 返回it1后一个元素
    vec.erase(it1, it2);

    // 重排
    std::sort(vec.begin(), vec.end());
    auto it3 = std::unique(vec.begin(), vec.end()); // 清除重复项 返回非重复末尾迭代器
    vec.erase(it3, vec.end());
    std::reverse(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end(), std::less<int>());
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    // 最值
    std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()));
}