#include <iostream>
#include <vector>
using namespace std;

#define debug

#define mod 9901
#define ll long long

vector<vector<ll>> factor;

int main()
{
    ll a, b;
    cin >> a >> b;

    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            factor.push_back(vector<ll>(b + 1, 1));
            factor.rbegin()->at(1) = i;
        }
    }

    for (int i = 0; i < factor.size(); i++)
    {
        for (int j = 2; j <= b; j++)
            factor[i][j] = factor[i][j - 1] * factor[i][1];
    }

#ifdef debug
    for (int i = 0; i < factor.size(); i++)
    {
        for (int j = 0; j < factor[0].size(); j++)
            cout << factor[i][j] << " ";
        cout << endl;
    }
#endif

    return 0;
}