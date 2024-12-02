#include <iostream>
#include <string>
#include <stack>
using namespace std;

int read(string exp, int &i)
{
    int rst = 0;
    while (exp[i] >= '0' && exp[i] <= '9')
        rst = rst % 1000 * 10 + exp[i++] - '0';
    return rst;
}

int main()
{
    string exp;
    cin >> exp;

    int idx = 0, x;
    stack<int> stk;
    while (idx < exp.size())
    {
        if (!idx)
            x = read(exp, idx);
        else if (exp[idx] == '+')
        {
            idx++;
            x = read(exp, idx);
        }
        else
        {
            idx++;
            x = read(exp, idx);
            x *= stk.top();
            x %= 10000;
            stk.pop();
        }
        stk.push(x);
    }

    int ans = 0;
    while (!stk.empty())
    {
        ans += stk.top();
        ans %= 10000;
        stk.pop();
    }

    cout << ans << endl;

    return 0;
}