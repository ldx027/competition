#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

vector<vector<int>> vec;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N + 1, vector<int>(N + 1));
    dp.resize(N + 1, vector<int>(N + 1, inf));
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> vec[i][j];

    
}