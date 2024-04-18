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

    int cnt = 0;
    vector<int> track(N);

    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;

        if (cnt == 0 || track[cnt - 1] < x)
        {
            track[cnt++] = x;
            continue;
        }
        auto it = lower_bound(track.begin(), track.begin() + cnt, x);
        *it = x;
    }

    cout << cnt << endl;

    return 0;
}