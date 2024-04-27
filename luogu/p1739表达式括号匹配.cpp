#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string exp;
    cin >> exp;

    stack<bool> stk;

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(') stk.push(true);
        else if (exp[i] == ')')
        {
            if (stk.empty())
            {
                cout << "NO" << endl;
                return 0;
            }

            stk.pop();
        }
    }

    cout << (stk.empty() ? "YES" : "NO") << endl;

    return 0;
}