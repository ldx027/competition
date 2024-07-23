#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> vec(N + 1);
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int i, b = 0;
    for (i = N - 1; i > 0; i--)
    {
        dp[i] = (vec[i + 1] - vec[i]) * (N - i) + dp[i + 1];
        if (dp[i] >= M)
        {
            while (dp[i] >= M + (N - i)) b++, dp[i] -= (N - i);
            break;
        } 
    }

    cout << vec[i] + b << endl;

    return 0;
}