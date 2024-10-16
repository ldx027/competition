#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Grass
{
    int l, r;
};
bool cmp(const Grass &a, const Grass &b) { return a.r < b.r; }

vector<Grass> grs;
vector<int> dp;

int n;

int main()
{
    cin >> n;

    dp.resize(n);
    grs.resize(n);

    for (int i = 0; i < n; i++)
        cin >> grs[i].l >> grs[i].r;
    sort(grs.begin(), grs.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        int last = -1;
        int l = 0, r = i - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (grs[mid].r < grs[i].l)
            {
                last = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        dp[i] = grs[i].r - grs[i].l + 1;
        if (last >= 0)
            dp[i] += dp[last];
    }

    // for (int i = 0; i < dp.size(); i++)
    //     cout << dp[i] << " ";
    // cout << endl;

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}