#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

vector<int> vec;

int bin(int l, int r, int c)
{
    // cout << l << " " << r << endl;
    if (l + 1 == r)
        return l;

    int cur = 0;
    int cnt = 1;
    int idx = 1;
    int mid = l + ((r - l) >> 1);

    while (1)
    {
        cur += vec[idx++];
        if (cur >= mid)
        {
            cnt++;
            cur = 0;
        }

        if (cnt == c)
            return bin(mid, r, c);
        if (idx == vec.size())
            return bin(l, mid, c);
    }
}

int main()
{
    ll n, c;
    cin >> n >> c;

    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int Max = *vec.rbegin();

    for (int i = n - 1; i > 0; i--)
        vec[i] -= vec[i - 1];
    
    // for (int i = 0; i < n; i++)
    //     cout << vec[i] << " ";
    // cout << endl;

    cout << bin(0, Max, c);

    return 0;
}