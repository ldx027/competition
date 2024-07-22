#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, s, a, b, x;
    cin >> n >> s >> a >> b;

    vector<int> y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y[i];
        if (x > a + b) y[i] = s + 1;
    }

    sort(y.begin(), y.end());

    int ans = 0;
    while (ans < y.size() && s >= y[ans])
    {
        s -= y[ans++];
    }

    cout << ans << endl;

    return 0;
}