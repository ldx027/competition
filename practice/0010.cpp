#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0, x;
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (!stk.empty() && stk.top() <= x) stk.pop();
        sum += stk.size();
        stk.push(x);
    }

    cout << sum << endl;

    return 0;
}