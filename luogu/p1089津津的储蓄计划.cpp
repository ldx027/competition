#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << str;

    return 0;
}