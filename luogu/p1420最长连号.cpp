#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++) cin >> vec[i];
    for (int i = 1; i < n; i++)
    {
        if (vec[i] - vec[i - 1] == 1) ans[i] = ans[i - 1] + 1;
    }

    cout << *max_element(ans.begin(), ans.end());

    return 0;
}