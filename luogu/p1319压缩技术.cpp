#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int total = 0;
    int cur = 0;
    int idx = 0;

    int x;
    while (total < N * N)
    {
        cin >> x;
        total += x;
        for (int i = 0; i < x; i++)
        {
            cout << idx;
            if (++cur == N) cout << endl, cur = 0;
        }
        idx = !idx;
    }

    return 0;
}