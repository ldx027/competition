#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> vec[i][j];
    
    for (int i = 0; i < n; i++)
    {
        int rst = -1;
        for (int j = 0; j < n; j++)
        {
            bool flg = true;
            for (int u = 0; u < m; u++)
            {
                if (vec[j][u] <= vec[i][u])
                {
                    flg = false;
                    break;
                }
            }
            if (flg)
            {
                if (rst == -1)
                    rst = j;
            }
        }
        cout << rst + 1 << endl;
    }

    return 0;
}