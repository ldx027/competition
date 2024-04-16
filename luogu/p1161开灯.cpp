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
    vector<bool> vec(2e6 + 3, false);

    double a;
    int t;
    while (n--)
    {
        cin >> a >> t;
        for (int i = 1; i <= t; i++) vec[int(a * i)] = !vec[int(a * i)];
    }

    for (int i = 1; i < 2e6 + 3; i++)
    {
        if (vec[i])
        {
            cout << i << endl;
            return 0;
        }
    }
}