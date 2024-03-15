#include <iostream>
#include <vector>
using namespace std;

vector<int> W;
vector<int> D;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    W.resize(N + 1);
    D.resize(N + 1);
    dp.resize(M + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> D[i];

    for (int i = 1; i <= N; i++)
    {
        for (int j = M; j >= W[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - W[i]] + D[i]);
        }
    }

    cout << dp[M];

    return 0;
}