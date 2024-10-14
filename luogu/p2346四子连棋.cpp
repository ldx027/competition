#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define debug

vector<vector<char>> map(4, vector<char>(4));

#ifdef debug
void show()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << map[i][j];
        cout << endl;
    }
}
#endif

int main()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> map[i][j];
    
    show();

    return 0;
}