#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;

    int x;
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = i + 1; j < n + 1; j++) sum[j] += x;
    }

    cin >> m;

    int l, r;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    
    return 0;
}