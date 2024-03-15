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
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    bool have = false;
    for (int i = 0; i < n; i++)
    {
        if (have) cout << " ";
        cout << vec[(i + m) % n];
        have = 1;
    }

    return 0;
}