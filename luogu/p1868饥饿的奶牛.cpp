#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Gras
{
    int l, r;
};
bool cmp(const Gras &a, const Gras &b) { return a.r < b.r; }
vector<Gras> gras;
vector<int> dp;

int main()
{
    int n;
    cin >> n;

    gras.resize(n + 1);
    dp.resize(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> gras[i].l >> gras[i].r;
    sort(gras.begin(), gras.end(), cmp);

    for (int i = 1; i <= n; i++)
    {
        int prev = -1;
        int l = 0, r = i - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (gras[mid].r < gras[i].l)
            {
                prev = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        dp[i] = gras[i].r - gras[i].l + 1;
        if (prev >= 0)
            dp[i] += dp[prev];
        dp[i] = max(dp[i - 1], dp[i]);
    }

    cout << dp[n] << endl;
}