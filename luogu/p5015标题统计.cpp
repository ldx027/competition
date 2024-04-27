#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    getline(cin, str);

    int cnt = 0;
    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (*it != ' ') ++cnt;
    }

    cout << cnt << endl;

    return 0;
}