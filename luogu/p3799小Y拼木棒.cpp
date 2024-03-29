#include <iostream>
#include <vector>
using namespace std;

#define mod int(1e9 + 7)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> vec(1e4, 0);

    int maxN = 0;
    int minN = 1e4;

    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        vec[x]++;

        minN = min(minN, x);
        maxN = max(maxN, x);
    }

    int ans = 0;
    for (int i = minN; i <= maxN; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            if (j != i - j)
                ans += vec[i] * (vec[i] - 1) / 2 * vec[j] * vec[i - j] % mod;
            else
                ans += vec[i] * (vec[i] - 1) / 2 * vec[j] * (vec[j] - 1) / 2 % mod;
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}
