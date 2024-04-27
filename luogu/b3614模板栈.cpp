#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll T;
    cin >> T;

    while (T--)
    {
        stack<ll> stk;

        ll n, x;
        string cmd;

        cin >> n;
        while (n--)
        {
            cin >> cmd;
            if (cmd == "push")
            {
                cin >> x;
                stk.push(x);
            }
            else if (cmd == "pop")
            {
                if (stk.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                    stk.pop();
            }
            else if (cmd == "query")
            {
                if (stk.empty())
                {
                    cout << "Anguei!" << endl;
                }
                else
                    cout << stk.top() << endl;
            }
            else if (cmd == "size")
            {
                cout << stk.size() << endl;
            }
        }
    }

    return 0;
}