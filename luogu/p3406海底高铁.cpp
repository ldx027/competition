#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll n, m;
vector<ll> p, A, B, C; // 目的地 票价 IC价 工本费
vector<ll> diff, num;

int main()
{
    cin >> n >> m;

    p.resize(m);
    A.resize(n + 1);
    B.resize(n + 1);
    C.resize(n + 1);
    diff.resize(n + 1, 0);
    num.resize(n + 1, 0);

    for (ll i = 0; i < m; i++)
        cin >> p[i];
    
    for (ll i = 1; i <= n; i++)
        cin >> A[i] >> B[i] >> C[i];
    
    for (ll i = 1; i < m; i++)
    {
        ll beg = p[i - 1];
        ll end = p[i];

        if (beg > end)
            beg ^= end ^= beg ^= end;
        
        diff[beg]++;
        diff[end]--;
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        num[i] = num[i - 1] + diff[i];
        ans += min(num[i] * A[i], num[i] * B[i] + C[i]);
    }

    // for (ll i = 1; i <= n; i++)
    //     cout << num[i] << " ";
    // cout << endl;

    cout << ans << endl;

    return 0;
}