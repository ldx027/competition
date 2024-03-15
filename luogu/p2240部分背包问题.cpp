#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coin
{
    int m;
    int v;
    Coin() {}
};
bool coinCmp(Coin c1, Coin c2)
{
    return double(c1.v) / c1.m >= double(c2.v) / c2.m;
}

vector<Coin> coins;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, T;
    cin >> N >> T;
    coins.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coins[i].m >> coins[i].v;
    }

    sort(coins.begin(), coins.end(), coinCmp);

    double ans = 0;
    int i = 0;
    for (i = 0; T >= coins[i].m; i++)
    {
        ans += coins[i].v;
        T -= coins[i].m;
    }
    ans += double(T) * coins[i].v / coins[i].m;

    printf("%.2f", ans);

    return 0;
}