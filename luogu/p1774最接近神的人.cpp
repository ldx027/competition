#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const ll maxN = 5e6 + 10;
// #define debug

vector<ll> tree(maxN), tag(maxN); 

void pushDown(ll idx, ll pl, ll pr)
{
    ll mid = pl + ((pr - pl) >> 1);
    tree[idx << 1] += tag[idx] * (mid - pl + 1);
    tag[idx << 1] += tag[idx];
    tree[idx << 1 | 1] += tag[idx] * (pr - mid);
    tag[idx << 1 | 1] += tag[idx];
    tag[idx] = 0;
}

void update(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        tree[idx] += val * (pr - pl + 1);
        tag[idx] += val;
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) update(l, r, idx << 1, pl, mid, val);
    if (mid < r) update(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

ll query(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
        return tree[idx];
    
    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    ll rst = 0;
    if (mid >= l) rst += query(l, r, idx << 1, pl, mid);
    if (mid < r) rst += query(l, r, idx << 1 | 1, mid + 1, pr);

    return rst;
}

vector<ll> vec;
vector<ll> buf;

int main()
{
    ll n;
    cin >> n;

    vec.resize(n);
    buf.resize(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        buf[i] = vec[i];
    }

    sort(buf.begin(), buf.end());
    buf.erase(unique(buf.begin(), buf.end()), buf.end());
    for (ll i = 0; i < n; i++)
        vec[i] = lower_bound(buf.begin(), buf.end(), vec[i]) - buf.begin() + 1;
    
#ifdef debug
    for (ll i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
#endif

    ll rst = 0;
    for (ll i = 0; i  < n; i++)
    {
        update(vec[i], vec[i], 1, 1, n, 1);
        rst += i - query(1, vec[i], 1, 1, n) + 1;
#ifdef debug
        cout << i - query(1, vec[i], 1, 1, n) + 1 << " ";
#endif
    }
#ifdef debug
    cout << endl;
#endif

    cout << rst << endl;

    return 0;
}