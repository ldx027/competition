#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int total = 0, first, num = 0;
    bool have = false;
    string str;

    while (1)
    {
        getline(cin, str);
        if (str == ".") break;
        total++;
        if (str.find("chi1 huo3 guo1") != string::npos)
        {
            if (!have)
            {
                have = true;
                first = total;
            }
            num++;
        }
    }

    cout << total << endl;
    if (have) cout << first << " " << num;
    else cout << "-_-#";

    return 0;
}