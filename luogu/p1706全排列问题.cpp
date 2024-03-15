#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool have(vector<int> vec, int begin, int end, int x)
{
    for (int i = begin; i < end; i++)
    {
        if (vec[i] == x) return 1;
    }
    return 0;
}

void dfs(vector<int> vec, int n, int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            printf("%5d", vec[i]);
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!have(vec, 0, idx + 1, i))
        {
            vec[idx] = i;
            dfs(vec, n, idx + 1);
        }
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> vec(10, 0);
    dfs(vec, n, 0);

    return 0;
}