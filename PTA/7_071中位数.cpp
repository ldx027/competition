#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec(2e5 + 10);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    while (cin >> n >> k)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.begin() + n);

        while (k--)
        {
            int idx = n / 2;
            while (vec[idx + 1] == vec[idx])
                idx++;
            vec[idx]++;
        }

        cout << vec[n / 2];
    }

    return 0;
}