#include <iostream>
using namespace std;

int main()
{
    int l, m;
    cin >> l >> m;
    int u, v;
    int *arr = new int[l + 1];
    for (int i = 0; i < l + 1; i++) arr[i] = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        for (int j = u; j <= v; j++)
            arr[j] = 0;
    }
    int ans = 0;
    for (int i = 0; i < l + 1; i++) if (arr[i]) ans++;
    cout << ans;
    return 0;
}