#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> vec1;
vector<int> vec2;
vector<int> dp;

int main()
{
    cin >> n;

    vec1.resize(n + 1);
    vec2.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> vec1[i];
    for (int i = 1; i <= n; i++)
        cin >> vec2[i];
    
    dp.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vec1[i] == vec2[j])
                dp[j] = dp[j - 1] + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}