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

    int N;
    cin >> N;
    vec.resize(N);
    dp.resize(N, 1);
    for (int i = 0; i < N; i++) cin >> vec[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[N - 1] << endl;

    return 0;       
}