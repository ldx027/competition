#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<int> vec(n + 1);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> vec[i];
        for (int j = 1; j <= n; j++)
        {
            dp[j] = max(dp[j - 1] + vec[j], 0);
        }
        int beg, end = max_element(dp.begin(), dp.end()) - dp.begin();
        for (beg = end; dp[beg - 1] > 0; beg--)
            ;
        if (*max_element(vec.begin() + 1, vec.end()) < 0)
        {
            beg = 1, end = n;
        }
        cout << *max_element(dp.begin(), dp.end()) << " " << vec[beg] << " " << vec[end] << endl;
    }

    return 0;
}