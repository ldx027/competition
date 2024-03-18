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

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int lower = lower_bound(vec.begin(), vec.end(), vec[i] - C) - vec.begin();
        int upper = upper_bound(vec.begin() + lower, vec.end(), vec[i] - C) - vec.begin();
        ans += upper - lower;
    }

    cout << ans << endl;

    return 0;
}