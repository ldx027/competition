#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;

void show(vector<vector<int>> vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 1; j < vec[i].size(); j++)
        {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
}

void trans(int x, int y, int r, int z)
{
    vector<vector<int>> temp(2 * r + 1, vector<int>(2 * r + 1, 0));
    for (int i = 0; i < 2 * r + 1; i++) for (int j = 0; j < 2 * r + 1; j++)
    {
        if (z)
        {
            temp[i][j] = vec[x - r + j][y + r - i];
        }
        else
        {
            temp[i][j] = vec[x + r - j][y - r + i];
        }
    }
    for (int i = 0; i < 2 * r + 1; i++) for (int j = 0; j < 2 * r + 1; j++)
    {
        vec[x - r + i][y - r + j] = temp[i][j];
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vec.resize(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) vec[i][j] = N * (i - 1) + j;

    int x, y, r, z;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> r >> z;
        trans(x, y, r, z);
    }
    show(vec);

    return 0;
}