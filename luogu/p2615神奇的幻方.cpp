#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> vec(N, vector<int>(N, 0));
    vec[0][N >> 1] = 1;

    pair<int, int> pos = {0, N >> 1};

    for (int i = 2; i <= N * N; i++)
    {
        if (pos.first == 0 && pos.second != (N - 1))
        {
            vec[N - 1][pos.second + 1] = i;
            pos = {N - 1, pos.second + 1};
        }
        else if (pos.second == N - 1 && pos.first != 0)
        {
            vec[pos.first - 1][0] = i;
            pos = {pos.first - 1, 0};
        }
        else if (pos.first == 0 && pos.second == N - 1)
        {
            vec[pos.first + 1][pos.second] = i;
            pos = {pos.first + 1, pos.second};
        }
        else if (vec[pos.first - 1][pos.second + 1] == 0)
        {
            vec[pos.first - 1][pos.second + 1] = i;
            pos = {pos.first - 1, pos.second + 1};
        }
        else
        {
            vec[pos.first + 1][pos.second] = i;
            pos = {pos.first + 1, pos.second};
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}