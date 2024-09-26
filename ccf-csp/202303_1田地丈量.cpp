#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vec.resize(n, vector<int>(4));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            cin >> vec[i][j];

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> point = vec[i];
        point[0] = max(0, point[0]);
        point[1] = max(0, point[1]);
        point[2] = min(a, point[2]);
        point[3] = min(b, point[3]);

        if (point[0] < point[2] && point[1] < point[3])
            ans += (point[2] - point[0]) * (point[3] - point[1]);
    }

    cout << ans << endl;

    return 0;
}