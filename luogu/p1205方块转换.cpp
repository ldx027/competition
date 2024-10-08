#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<bool>> vec1;
vector<vector<bool>> vec2;

int main()
{
    cin >> n;
    
    vec1.resize(n, vector<bool>(n));
    vec2.resize(n, vector<bool>(n));

    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            vec1[i][j] = (c == '@');
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            vec2[i][j] = (c == '@');
        }
    }

    
}