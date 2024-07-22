#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int w, n;
    cin >> w >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == 0) continue;
        for (int j = n - 1; j > i; j--)
        {
            if (vec[j] != 0 && vec[i] + vec[j] <= w)
            {
                vec[j] = 0;
                break;
            }
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}