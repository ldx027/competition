#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    char x;
    cin >> N >> M;
    vector<vector<char>> vec(3 * N, vector<char>(3 * M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> x;
            if (x == 'S')
            {
                vec[N + i][M + i] = 'S';
                x = '.';
            }
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    vec[N * n + i][M * m + j] = x;
                }
            }
        }
    }
}