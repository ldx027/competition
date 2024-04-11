#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> vec(n, vector<char>(n));
    vector<vector<bool>> vec2(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> vec[i][j];

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
    }
}