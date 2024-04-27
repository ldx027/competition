#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool huiwen(string str)
{
    for (int i = 0; i < str.size() / 2; i++)
        if (str[i] < 'a' || str[i] > 'z' || str[i] != str[str.size() - 1 - i])
            return false;
    return true;
}

bool func(string str)
{
    vector<bool> vec(26, true);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < 'a' || str[i] > 'z') return false;
        if (!vec[str[i] - 'a']) return false;
        vec[str[i] - 'a'] = false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    string str;
    cin >> T;

    while (T--)
    {
        bool flg = false;
        cin >> str;
        for (int i = str.size() - 1; i > 0; i--)
        {
            // cout << str.substr(0) << " " << str.substr(0, 0) << endl;
            if (huiwen(str.substr(i)) && func(str.substr(0, i)))
            {
                cout << "HE" << endl;
                flg = true;
                break;
            }
        }
        if (!flg) cout << "NaN" << endl;
    }

    return 0;
}