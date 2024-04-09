#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    vector<pair<int, int>> ans;
    vector<int> worker(m, 0);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int l = 0, r = 0;
    worker[vec[0] - 1] = 1;
    while (1)
    {
        bool flg = true;
        for (int i = 0; i < worker.size(); i++)
        {
            if (!worker[i])
                flg = false;
        }
        if (flg)
        {
            ans.push_back({r - l, l});
            worker[vec[l++] - 1]--;
        }
        else
        {
            if (r == n - 1)
                break;
            worker[vec[++r] - 1]++;
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0].second + 1 << " " << ans[0].first + ans[0].second + 1 << endl;

    return 0;
}