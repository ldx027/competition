#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> map(M);
    for (int i = 0; i < M; i++)
    {
        cin >> map[i];
        map[i]--;
    }
    
    vector<vector<long long>> vec(N, vector<long long>(N, 0x3f3f3f3f)); 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < N; i++) vec[i][i] = 0;
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < M; i++)
    {
        ans += vec[map[i - 1]][map[i]];
    }

    cout << ans;

    return 0;
}