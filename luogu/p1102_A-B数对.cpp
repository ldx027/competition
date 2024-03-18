#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

vector<ll> vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C;
    cin >> N >> C;

    vec.resize(N);
    for (int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        auto lower = lower_bound(vec.begin(), vec.end(), vec[i] - C);
        auto upper = upper_bound(lower, vec.end(), vec[i] - C);
        if (lower != vec.end())
            ans += upper - lower;
    }

    cout << ans << endl;

    return 0;
}