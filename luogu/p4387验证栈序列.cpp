#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int q;
    int n, x;
    cin >> q;


    for (int i = 0; i < q; i++)
    {
        cin >> n;
        vector<int> in;
        stack<int> stk;
        queue<int> que;

        for (int j = 0; j < n; j++)
        {
            cin >> x;
            in.push_back(x);
        }
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            que.push(x);
        }

        bool can = true;
        auto it = in.begin();
        while (!que.empty())
        {
            if (!stk.empty() && stk.top() == que.front())
            {
                stk.pop();
                que.pop();
            }
            else
            {
                if (it == in.end())
                {
                    can = false;
                    break;
                }
                stk.push(*it);
                it++;
            }
        }

        cout << (can ? "Yes" : "No") << endl;
    }

    return 0;
}