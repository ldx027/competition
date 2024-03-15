#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
void dfs(int x, int N)
{
    if (x >= N) return;
    dfs(2 * x + 1, N);
    dfs(2 * x + 2, N);
    cin >> vec[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N);
    dfs(0, N);

    bool flg = false;
    for (int i = 0; i < N; i++)
    {
        if (flg) cout << " ";
        cout << vec[i];
        flg = true;
    }

    return 0;
}