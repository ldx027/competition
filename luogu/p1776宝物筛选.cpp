#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, W;
vector<int> v;
vector<int> w;
vector<int> dp;

void show(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n >> W;

    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        for (int j = 1; j <= c; j <<= 1)
        {
            c -= j;
            v.push_back(j * a);
            w.push_back(j * b);
        }
        if (c)
        {
            v.push_back(c * a);
            w.push_back(c * b);
        }
    }


    dp.resize(W + 1, 0);

    for (int i = 0; i < v.size(); i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[W] << endl;

    return 0;
}
