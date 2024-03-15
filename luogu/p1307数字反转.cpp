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
    int fh = 1;
    cin >> str;
    if (str[0] == '-')
    {
        fh = 0;
        str = str.substr(1);
    }
    reverse(str.begin(), str.end());
    int idx = 0;
    while (str.size() != 1 && str[idx] == '0')
    {
        idx++;
    }
    str = str.substr(idx);

    if (!fh) cout << "-";
    cout << str << endl;

    return 0;
}