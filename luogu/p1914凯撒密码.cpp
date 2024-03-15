#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        str[i] = (str[i] - 'a' + n + 26) % 26 + 'a';
    }

    cout << str << endl;

    return 0;
}