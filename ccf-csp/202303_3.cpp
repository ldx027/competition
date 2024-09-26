#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <string>
using namespace std;

#define wtf cout << "wtf" << endl

map<int, unordered_map<int, int>> mp;

bool query(int dn, string exp)
{
    // cout << "exp";
    // cout << exp << endl;
    if (exp[0] == '&' || exp[0] == '|')
    {
        int cnt = 1;
        int len = 0;

        while (cnt)
        {
            len++;
            if (exp[1 + len] == '(')
                cnt++;
            else if (exp[1 + len] == ')')
                cnt--;
        }

        // cout << "len";
        // cout << len << endl;

        exp.erase(exp.size() - 1);

        if (exp[0] == '&')
            return query(dn, exp.substr(2, len - 1)) && query(dn, exp.substr(3 + len));
        else if (exp[0] == '|')
            return query(dn, exp.substr(2, len - 1)) || query(dn, exp.substr(3 + len));
    }
    else
    {
        int x = 0, y = 0;
        char c;
        int idx = 0;

        while (exp[idx] >= '0' && exp[idx] <= '9')
            x = 10 * x + exp[idx++] - '0';
        c = exp[idx++];
        while (idx < exp.size())
            y = 10 * y + exp[idx++] - '0';

        if (c == ':')
        {
            return mp[dn].count(x) && mp[dn][x] == y;
        }
        else if (c == '~')
        {
            return mp[dn].count(x) && mp[dn][x] != y;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int dn, x, y, z;
    for (int i = 0; i < n; i++)
    {
        cin >> dn >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> y >> z;
            mp[dn][y] = z;
        }
    }

    int m;
    cin >> m;

    string exp;
    while (m--)
    {
        cin >> exp;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (query(it->first, exp))
                cout << it->first << " ";
        }
        cout << endl;
    }

    return 0;
}