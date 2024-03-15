#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> que;
vector<vector<bool>> vst;
bool dfs(vector<vector<int>> &vec, int x, int y, int n)
{
    if (vec[x][y] || vst[x][y]) return false;
    que.push({x, y});
    vst[x][y] = 1;
    if (x == n - 2 && y == n - 2)
    {
        while (!que.empty())
        {
            printf("(%d,%d)", que.front().first, que.front().second);
            que.pop();
        }
        return true;
    }

    bool rst = true;
    rst = rst && dfs(vec, x + 1, y, n);
    rst = rst && dfs(vec, x, y + 1, n);
    rst = rst && dfs(vec, x - 1, y, n);
    rst = rst && dfs(vec, x, y - 1, n);
    que.pop();
    vst[x][y] = 0;

    return rst;
}

vector<vector<int>> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vec.resize(n, vector<int>(n));
    vst.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> vec[i][j];
    dfs(vec, 1, 1, n);

    return 0;
}