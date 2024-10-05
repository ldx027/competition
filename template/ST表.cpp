#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<int> vec;
vector<vector<int>> Max;
vector<vector<int>> Min;
vector<int> LOG2;

void init()
{
    LOG2.resize(n + 2, -1);
    for (int i = 1; i <= n + 1; i++)
        LOG2[i] = LOG2[i >> 1] + 1;
    
    Max.resize(n + 1, vector<int>(LOG2[n] + 1));
    Min.resize(n + 1, vector<int>(LOG2[n] + 1));

    for (int i = 1; i <= n; i++)
        Max[i][0] = Min[i][0] = vec[i];
    
    for (int i = 1; i <= LOG2[n]; i++)
    {
        for (int j = 1; j + (1 << (i - 1)) <= n; j++)
        {
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int query(int l, int r)
{
    int k = LOG2[r - l + 1];
    int a = max(Max[l][k], Max[r - (1 << k) + 1][k]);
    int b = min(Min[l][k], Min[r - (1 << k) + 1][k]);

    return a - b;
}

int main()
{
    cin >> n >> q;

    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];
    
    init();
    
    int u, v;
    while (q--)
    {
        cin >> u >> v;
        cout << query(u, v) << endl;
    }

    return 0;
}