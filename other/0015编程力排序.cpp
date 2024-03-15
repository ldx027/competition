#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<set<int>> vec(N);

    int maxIdx = 0;
    int max = 0;
    int u, v;
    for (int i = 0; i < N; i++)
    {
        int write = 0;
        cin >> u >> v;
        if (u > max)
        {
            max = u;
            write = 1;
        }
        int idxu = u - 1;
        if (write)
        {
            maxIdx = idxu;
        }
        for (int j = 0; j < N; j++)
        {
            if (vec[j].count(u))
            {
                idxu = j;
                break;
            }
        }
        vec[idxu].insert(u);
        vec[idxu].insert(v);
        printf("u%d v%d idx%d\n", u, v, idxu);
    }

    for (int i = 0; i < N; i++)
    {
        cout << vec[i].size() << endl;
    }

    cout << endl << endl;
    cout << vec[maxIdx].size() << endl;

    return 0;
}