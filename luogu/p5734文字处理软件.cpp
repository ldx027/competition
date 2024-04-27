#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    string doc;
    cin >> doc;

    int cmd, a, b;
    string str;

    while (q--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> str;
            doc += str;
            cout << doc << endl;
        }
        else if (cmd == 2)
        {
            cin >> a >> b;
            doc = doc.substr(a, b);
            cout << doc << endl;
        }
        else if (cmd == 3)
        {
            cin >> a >> str;
            doc.insert(a, str);
            cout << doc << endl;
        }
        else if (cmd == 4)
        {
            cin >> str;
            int idx = doc.find(str);
            cout << (idx == string::npos ? -1 : idx) << endl;
        }
    }

    return 0;
}