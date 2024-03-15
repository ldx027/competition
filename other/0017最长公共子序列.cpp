#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a, b;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    dp.resize(a.size() + 1, vector<int>(b.size() + 1));

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1; 
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    
    cout << dp[a.size()][b.size()] << endl;

    return 0;
}