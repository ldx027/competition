#include <iostream>
#include <stack>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N;
    cin >> N;

    ll ans = 0, x;
    stack<ll> stk;
    for (ll i = 0; i < N; i++)
    {
        cin >> x;
        while (stk.size() && x >= stk.top()) stk.pop();
        ans += stk.size();
        stk.push(x);
    }
    cout << ans << endl;

    return 0;
}