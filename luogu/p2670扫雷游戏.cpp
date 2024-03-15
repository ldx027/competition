#include <iostream>
#include <vector>
using namespace std;

void show(vector<vector<char>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
        }
        printf("\n");
    }
}

vector<vector<char>> scanf(vector<vector<char>> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] != '*')
            {
                map[i][j] = '0';
                for (int m = -1; m < 2; m++)
                {
                    for (int n = -1; n < 2; n++)
                    {
                        if (i + m >= 0 && i + m < map.size() && j + n >= 0 && j + n < map[0].size())
                        {
                            if (map[i + m][j + n] == '*')
                            {
                                map[i][j]++;
                            }
                        }
                    }
                }
            }
        }
    }

    return map;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    map = scanf(map);

    show(map);
    
    return 0;
}