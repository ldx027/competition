#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> group;

int main()
{
    int m, n, T;
    cin >> m >> n;

    group.resize(m);

    for (int i = 0; i < m; i++)
        cin >> group[i];

    vector<queue<int>> ques(n); 
    queue<queue<int>*> list;

    cin >> T;

    string cmd;
    int x;
    while (T--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> x;
            ques[group[x]].push(x);
            if (ques[group[x]].size() == 1)
                list.push(&ques[group[x]]);
        }
        else
        {
            cout << list.front()->front() << endl;
            list.front()->pop();
            if (list.front()->empty())
                list.pop();
        }
    }

    return 0;
}