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

    for (int i = str.size() - 1; i > 0; i--)
    {
        for (int j = 0; j + i < str.size(); j++)
        {
            if (str.rfind(str.substr(j, i)) != j)
            {
                cout << str << endl;
                cout << str.substr(j, i) << endl;
                return 0;
            }
        }
    }
    cout << str << endl << "NULL" << endl;

    return 0;
}