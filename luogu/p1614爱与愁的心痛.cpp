#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i];

    int cur = 0, Min;
    for (int i = 0; i < m; i++) cur += vec[i];
    Min = cur;

    for (int i = m; i < n; i++)
    {
        Min = min(Min, cur += vec[i] - vec[i - m]);
    }

    cout << Min << endl;

    return 0;
}