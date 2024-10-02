#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int n, S, T;
vector<double> vec;

#define debug

bool check(double mid)
{
    vector<double> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + vec[i] - mid;

    deque<pair<double, int>> que;

    for (int i = S; i <= n; i++)
    {
        while (!que.empty() && que.back().first >= sum[i - S])
            que.pop_back();
        while (!que.empty() && i - que.front().second > T)
            que.pop_front();
        que.push_back({sum[i - S], i - S});
        
        // cout << sum[i] << " " << que.front().first << endl;
        if (sum[i] - que.front().first >= 0)
            return true;
    }

    return false;
}

int main()
{
    cin >> n >> S >> T;
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    double l = -1e4, r = 1e4;
    double ans;
    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            ans = l = mid;
        else
            r = mid;
    }

    printf("%.3lf", l);

    return 0;
}