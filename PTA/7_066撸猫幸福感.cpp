#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    while (cin >> x) vec.push_back(x);
    if (vec.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    dp.resize(vec.size(), 0);
    if (dp.size() > 0) dp[0] = vec[0];
    if (dp.size() > 1) dp[1] = vec[1];

    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + vec[i]);
    }

    cout << *dp.rbegin() << endl;

    return 0;
}