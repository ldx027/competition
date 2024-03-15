#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int cmd, d;
    while (n--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> d;
            stk.push(d);
        }
        else
        {
            if (stk.empty())
            {
                cout << "invalid" << endl;
            }
            else
            {
                cout << stk.top() << endl;
                stk.pop();
            }
        }
    }

    return 0;
}