#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;
vector<int> input;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++) cin >> input[i];
    dp.resize(*max_element(input.begin(), input.end()) + 1, 0);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 0; i < input.size(); i++) cout << dp[input[i]] << endl;

    return 0;
}