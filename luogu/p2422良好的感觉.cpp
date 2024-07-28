#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

#define ll long long
#define wtf std::cout<<"wtf"<<std::endl

vector<ll> vec;
vector<ll> sumvec;

ll lowbit(ll x) { return x & -x; }

void add(int idx, ll x)
{
    while (idx < sumvec.size())
    {
        sumvec[idx] += x;
        idx += lowbit(idx);
    }
}

ll sum(int idx)
{
    ll rst = 0;
    while (idx > 0)
    {
        rst += sumvec[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

int main()
{
    int N;
    cin >> N;

    vec.resize(N + 3, 0);
    sumvec.resize(N + 3, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> vec[i];
        add(i, vec[i]);
    }

    vector<int> left(N + 2, 1), right(N + 2, N);
    stack<pair<ll, int>> stk;

    for (int i = 1; i <= N + 1; i++)
    {
        while (!stk.empty() && stk.top().first > vec[i])
        {
            right[stk.top().second] = i - 1;
            stk.pop();
        }
        left[i] = stk.empty() ? 1 : stk.top().second + 1;
        stk.push({vec[i], i});
    }

    // for (int i = 1; i <= N; i++) cout << left[i] << " "; cout << endl;
    // for (int i = 1; i <= N; i++) cout << right[i] << " "; cout << endl;
    // for (int i = 0; i <= N; i++) cout << sum(i) << " "; cout << endl;

    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, (sum(right[i]) - sum(left[i] - 1)) * vec[i]);
    }

    cout << ans << endl;
    // wtf;

    return 0;
}