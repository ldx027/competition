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
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    vector<int> sum(n + 1, 0);
    for (int i = 1; i < n + 1; i++) sum[i] = sum[i - 1] + vec[i - 1];

    cin >> m;

    int l, r;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    
    return 0;
}