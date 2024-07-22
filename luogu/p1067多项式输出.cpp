#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    for (int i = 0; i <= n; i++) cin >> vec[i];

    int cur = 0;
    while (!vec[cur] && cur < n) ++cur;

    if (vec[cur] < 0) cout << "-";
    cout << abs(vec[cur]) << "x^" << n - cur;

    for (cur++; cur <= n; cur++)
    {
        if (vec[cur] == 0) continue; 

        if (vec[cur] > 0) cout << "+";
        else cout << "-";

        if (abs(vec[cur]) != 1 || n - cur == 0) cout << abs(vec[cur]);

        if (n - cur == 0) continue;
        else if (n - cur == 1) cout << "x";
        else cout << "x^" << n - cur;
    }

    return 0;
}