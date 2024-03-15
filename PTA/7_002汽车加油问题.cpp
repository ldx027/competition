#include <iostream>
#include <vector>
using namespace std;

vector<int> dis;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    dis.resize(k + 1);
    for (int i = 0; i < k + 1; i++) cin >> dis[i];

    int oil = n, sta = 0;
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        oil -= dis[i];
        // cout << oil << " ";
        while (oil <= 0)
        {
            if (sta == 0)
            {
                cout << "No Solution!" << endl;
                return 0;
            }
            else
            {
                // cout << i << endl;
                oil += n;
                sta--;
                ans++;
            }
        }
        sta++;
    }

    cout << ans << endl;

    return 0;
}