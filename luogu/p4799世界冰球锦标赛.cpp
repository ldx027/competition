#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #define debug
#define ll long long

ll n, m;
vector<ll> vec;
vector<ll> res1, res2;

#ifdef debug
template <typename T>
void show(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
#endif

void dfs(ll idx, ll t, int res, ll sum = 0)
{
#ifdef debug
    // cout << idx << " " << t << endl;
#endif
    if (idx == t)
    {
        if (sum <= m)
        {
            if (res == 1)
                res1.push_back(sum);
            else
                res2.push_back(sum);
        }
        return;
    }

    dfs(idx + 1, t, res, sum);
    dfs(idx + 1, t, res, sum + vec[idx]);
}

int main()
{
    cin >> n >> m;

    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());
    vec.erase(upper_bound(vec.begin(), vec.end(), m), vec.end());

    ll mid = vec.size() >> 1;

    dfs(0, mid, 1);
    dfs(mid, vec.size(), 2);
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());

#ifdef debug
    cout << "vec" << endl;
    show(vec);
    cout << "mid ";
    cout << mid << endl;
    cout << "res1" << endl;
    show(res1);
    cout << "res2" << endl;
    show(res2);
#endif

    ll ans = 0;
    for (int i = 0; i < res2.size() && res2[i] <= m; i ++)
        ans += upper_bound(res1.begin(), res1.end(), m - res2[i]) - res1.begin();

    cout << ans << endl;

    return 0;
}