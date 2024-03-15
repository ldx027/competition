#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isP(int x)
{
    if (x <= 1)
        return false;
    if (x == 2 || x == 3)
        return true;
    int n = x % 6;
    if (n % 2 == 0 || n == 3)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    vector<char> vec(26, 0);

    cin >> str;
    for (auto it = str.begin(); it != str.end(); it++)
        vec[*it - 'a']++;

    int max = *max_element(vec.begin(), vec.end());
    int min = 1000;
    for (int i = 0; i < 26; i++)
        if (vec[i] != 0)
            min = (min > vec[i] ? vec[i] : min);
    int num = max - min;

    if (isP(num))
    {
        cout << "Lucky Word" << endl
             << num << endl;
    }
    else
    {
        cout << "No Answer" << endl
             << 0 << endl;
    }

    return 0;
}