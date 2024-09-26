#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    vector<int> vec(N);
    vector<vector<bool>> rd(N, vector<bool>(N, false));
    vector<int> dp(N);
    vector<int> prev(N, -1);

    for (int i = 0; i < N; i++)
        cin >> vec[i];
    
    for (int i = 0; i < N; i++)
        dp[i] = vec[i];

    int x;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            cin >> x;
            if (x)
                rd[i][j] = rd[j][i] = 1;
        }
    }

    for (int i = 1; i < N; i++)
    {

    }
}