#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main()
{
    set<int> s;
    set<int>::iterator l, r;
    pair<set<int>::iterator, bool> rt;

    int n;
    cin >> n;

    int cmd, len;
    while (n--)
    {
        cin >> cmd >> len;
        if (cmd == 1)
            if (!s.insert(len).second)
                cout << "Already Exist\n";
            else if (cmd == 2)
            {
                if (s.count(len))
                {
                    cout << len << endl;
                    s.erase(len);
                }
                else
                {
                    l = r = s.insert(len).first;
                    l--, r++;
                    if (l == s.begin() && r == s.end())
                        cout << "Empty\n";
                    else if (l == s.begin())
                        cout << *r << endl;
                    else if (r == s.end())
                        cout << *r << endl;
                    else
                        cout << ((*r - len > len - *l) ? *r : *l) << endl;
                    s.erase(len);
                }
            }
    }

    return 0;
}