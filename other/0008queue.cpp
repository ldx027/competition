#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string cmd;
    list<char> lst;
    int games = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "start")
        {
            if (lst.size() < 1)
            {
                cout << "Error" << endl;
            }
            else
            {
                for (int i = 0; i < 2 - games; i++)
                {
                    lst.pop_front();
                    cout << lst.front() << " ";
                    lst.push_back(lst.front());
                }
                cout << endl;
            }
        }

        else if (cmd == "arrive")
        {
            char x;
            cin >> x;
            int have = 0;
            for (auto it2 = lst.begin(); it2 != lst.end(); it2++)
            {
                if (*it2 == x)
                {
                    have = 1;
                    break;
                }
            }
            if (have)
            {
                cout << "Error" << endl;
            }
            else
            {
                lst.push_back(x);
                cout << "OK" << endl;
            }
        }

        else if (cmd == "leave")
        {
            char x;
            cin >> x;
            auto it2 = lst.begin();
            for (int i = 0; i < 2; i++)
            {
                it2++;
                if (it2 == lst.end()) break;
            }
            while (it2 != lst.end() && *it2 != x) it2++;
            if (it2 == lst.end())
            {
                cout << "Error" << endl;
            }
            else
            {
                lst.erase(it2);
                cout << "OK" << endl;
            }
        }
    }

    return 0;
}