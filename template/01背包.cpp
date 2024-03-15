#include <iostream>
#include <vector>
using namespace std;

vector<int> w;
vector<int> v;
vector<int> dp;

int main()
{
    int N, M;
    cin >> N >> M;

    w.resize(M);
    v.resize(M);
    dp.resize(N + 1, 0);
    
    for (int i = 0; i < M; i++) cin >> w[i] >> v[i];

    for (int i = 0; i < M; i++)
    {
        for (int j = N; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[N] << endl;
}
