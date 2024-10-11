#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

unordered_map<string, string> func;
unordered_map<string, int> mp1, mp2;
queue<string> ori, opp;
string A, B;

int main()
{
    cin >> A >> B;

    string from, to;
    while (cin >> from >> to)
        func[from] = to;

    mp1[A] = 0, mp2[B] = 0;
    ori.push(A), opp.push(B);

    while (!ori.empty() && !opp.empty())
    {
        if (mp1[ori.front()] + mp2[opp.front()] > 10)
            break;

        string tmp;
        int idx;
        for (auto it = func.begin(); it != func.end(); it++)
        {
            if ((idx = ori.front().find(it->first)) != string::npos)
            {
                tmp = ori.front();
                tmp.erase(idx, it->first.size());
                tmp.insert(idx, it->second);
                if (mp1.count(tmp))
                    continue;
                mp1[tmp] = mp1[ori.front()] + 1;
                ori.push({tmp, mp1[tmp]});
                cout << tmp << endl;

                if (mp2.count(tmp))
                {
                    cout << mp1[tmp] + mp2[tmp] << endl;
                    return 0;
                }
            }

            if ((idx = opp.front().find(it->second)) != string::npos)
            {
                tmp = opp.front();
                tmp.erase(idx, it->second.size());
                tmp.insert(idx, it->first);
                if (mp2.count(tmp))
                    continue;
                mp2[tmp] = mp2[opp.front()] + 1;
                opp.push({tmp, mp2[tmp]});
                cout << tmp << endl;

                if (mp1.count(tmp))
                {
                    cout << mp1[tmp] + mp2[tmp] << endl;
                    return 0;
                }
            }
        }

        ori.pop();
        opp.pop();
    }

    return 0;
}