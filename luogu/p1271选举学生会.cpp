#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec.resize(n + 1, 0);

    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        vec[x]++;
    }

    for (int i = 1; i <= n; i++) while (vec[i]--) cout << i << " ";

    return 0;
}