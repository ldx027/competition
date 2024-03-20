#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n + 1, 0);
    vector<int> ans(n + 1, 0);
    stack<int> stk;

    for (int i = 1; i <= n; i++) cin >> vec[i];

    for (int i = n; i >= 1; i--)
    {
        while (!stk.empty() && vec[stk.top()] <= vec[i]) stk.pop();
        ans[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}