#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
    int N;
    cin >> N;

    stack<int> input, output;
    stack<pair<int, int>> stk;

    int x;
    for (int i = 0; i < N; i++)
        cin >> x, input.push(x);

    for (int i = N; i > 0; i--)
    {
        int cur = input.top();
        input.pop();

        while (!stk.empty() && stk.top().first <= cur) stk.pop();

        if (stk.empty()) output.push(0);
        else output.push(stk.top().second);

        stk.push({cur, i});
    }

    while (!output.empty())
    {
        cout << output.top() << endl;
        output.pop();
    }

    return 0;
}