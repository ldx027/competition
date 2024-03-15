#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, N, x;
    cin >> L >> N >> x;

    int _min = min(x, L + 1 - x);
    int _max = max(x, L + 1 - x);

    for (int i = 1; i < N; i++)
    {
        cin >> x;
        _min = max(_min, min(x, L + 1 - x));
        _max = max(_max, max(x, L + 1 - x));
    }

    cout << _min << " " << _max;

    return 0;
}