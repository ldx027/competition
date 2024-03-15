#include <iostream>
#include <vector>
using namespace std;

int vol(vector<vector<vector<bool>>> &vec, int x, int y, int z)
{

}

vector<vector<vector<bool>>> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N, L, T;
    cin >> M >> N >> L >> T;
    vec.resize(M, vector<vector<bool>>(N, vector<bool>(L)));

    bool x;
    for (int u = 0; u < L; u++)
    {
        for (int v = 0; v < M; v++)
        {
            for (int w = 0; w < N; w++)
            {
                cin >> x;
                vec[u][v][w] = x;
            }
        }
    }
}