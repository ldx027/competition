#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define ll long long
#define wtf cout<<"wtf"<<endl

vector<pair<int, int>> vec;
vector<int> nums;
vector<int> inverse;

ll lowbit(ll x)
{
    return x & -x;
}

void add(ll x, ll idx)
{
    while (idx < inverse.size())
    {
        inverse[idx] += x;
        idx += lowbit(idx);
    }
}

ll sum(ll idx)
{
    ll rst = 0;
    while (idx > 0)
    {
        rst += inverse[idx];
        idx -= lowbit(idx);
    }
    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vec.resize(n);
    nums.resize(n);
    inverse.resize(n + 1, 0);
    for (ll i = 0; i < n; i++) cin >> vec[i].first, vec[i].second = i;
    sort(vec.begin(), vec.end());
     
    for (ll i = 0; i < n; i++) nums[vec[i].second] = i + 1;

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        add(1, nums[i]);
        ans += i + 1 - sum(nums[i]);
    }

    cout << ans << endl;

    return 0;
}