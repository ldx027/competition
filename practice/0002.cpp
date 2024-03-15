#include <iostream>
#include <vector>
using namespace std;

vector<int> w;
vector<int> v;
vector<int> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C;
    cin >> N >> C;
    w.resize(N);
    v.resize(N);
    dp.resize(C + 1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = C; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[C] << endl;

    return 0;
}