#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < a.size() - 1; j++)
        {
            if (b[j] == a[i + 1] && b[j + 1] == a[i])
            {
                ans++;
                break;
            }
        }
    }

    cout << (1 << ans) << endl;

    return 0;
}