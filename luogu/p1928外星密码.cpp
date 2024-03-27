#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    int pos;

    cin >> str;

    while ((pos = str.rfind('[')) != string::npos)
    {
        // cout << pos << endl;
        int n = 0;
        string X = "";
        int i;
        for (i = pos + 1; i < str.size() && str[i] != ']'; i++)
        {
            if (str[i] >= '0' && str[i] <= '9') n = 10 * n + str[i] - '0';
            else X += str[i];
        }

        str.erase(pos, i - pos + 1);
        while (n--) str = str.insert(pos, X);
        // cout << str << endl;
    }

    cout << str << endl;

    return 0;
}
