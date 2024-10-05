#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll L, N, M;
vector<ll> vec;

bool check(ll mid)
{
    ll cur = 0, cnt = 0, nxt = 1;

    while (nxt <= N + 1)
    {
        if (vec[nxt] - vec[cur] < mid)
            cnt++;
        else
            cur = nxt;
        nxt++;
    }

    return cnt <= M;
}

int main()
{
    cin >> L >> N >> M;

    vec.resize(N + 2);
    for (ll i = 1; i <= N; i++)
        cin >> vec[i];
    vec[N + 1] = L;

    ll l = 0, r = L;
    ll ans;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        ll mid = l + ((r - l) >> 1);
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ans << endl;

    return 0;
}
