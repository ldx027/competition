#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

#define ll long long
#define pi 3.1415926

struct Node
{
    double x, y, r = 0;
};

ll N;
double x, y, X, Y;
vector<Node> vec;
vector<Node> buf;

unordered_set<ll> st;
double Max = 0;
void dfs(ll idx = 0)
{
    if (idx == N)
    {
        double rst = 0;
        for (int i = 0; i < N; i++)
            rst += pi * buf[i].r * buf[i].r;
        Max = max(Max, rst);
        return;
    }

    for (ll i = 0; i < N; i++)
    {
        if (st.count(i))
            continue;
        st.insert(i);
        buf[idx] = vec[i];

        double r = min(vec[i].x - x, vec[i].y - y);
        r = min(r, X - vec[i].x);
        r = min(r, Y - vec[i].y);
        for (int j = 0; j < idx; j++)
            r = min(r, sqrt(pow(vec[i].x - buf[j].x, 2) + pow(vec[i].y - buf[j].y, 2)) - buf[j].r);
        r = max(r, .0);
        buf[idx].r = r;

        dfs(idx + 1);
        st.erase(i);
    }
}

int main()
{
    cin >> N;
    cin >> x >> y >> X >> Y;

    double tmp;
    if (x > X)
    {
        tmp = x;
        x = X;
        X = tmp;
    }
    if (y > Y)
    {
        tmp = y;
        y = Y;
        Y = tmp;
    }

    vec.resize(N);
    buf.resize(N);
    for (ll i = 0; i < N; i++)
        cin >> vec[i].x >> vec[i].y;

    dfs();

    cout << (ll)(0.5 + (X - x) * (Y - y) - Max) << endl;

    return 0;
}