#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int sum = -0x3f3f3f3f, ans = -0x3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
        sum = max(vec[i], sum + vec[i]);
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}