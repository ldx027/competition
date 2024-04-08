#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node
{
    int x, y;
    int stp;
    string str;
};

vector<vector<char>> vec(30, vector<char>(50));
vector<vector<bool>> vst(30, vector<bool>(50, false));

void bfs()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 30; i++) for (int j = 0; j < 50; j++) cin >> vec[i][j];
}