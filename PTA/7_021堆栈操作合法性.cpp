#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string str;
    int len = 0;
    while (n--)
    {
        cin >> str;
        len = 0;
        for (auto it = str.begin(); it != str.end(); it++)
        {
            if (*it == 'S' && ++len > m) break;
            else if (*it == 'X' && --len < 0) break;
        }
        cout << (len == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}