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
    vector<bool> est(2e4 + 3, false);
    vector<int> have(2e4 + 3, false);

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 0; j < i; j++)
        {
            have[x + vec[j]] = true;
        }
        vec[i] = x;
        est[x] = true;
    }

    int cnt = 0;
    for (int i = 0; i < 2e4 + 3; i++)
    {
        if (est[i] && have[i]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
