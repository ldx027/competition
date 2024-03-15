#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vec.resize(n);
    dp.resize(n, 1);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    for (int i = 1; i < n; i++)
    {
        if (vec[i] > vec[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
    }

    auto it = max_element(dp.begin(), dp.end());
    int beg = it - dp.begin() - *it + 1;

    bool have = 0;
    for (int i = beg; i < beg + *it; i++)
    {
        if (have) cout << " ";
        cout << vec[i];
        have = 1;
    }

    return 0;
}