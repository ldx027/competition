#include <iostream>
#include <vector>
using namespace std;

int A, B, C, m;
vector<vector<vector<int>>> vec;
vector<vector<int>> attack;

bool check(int mid)
{
    vector<vector<vector<int>>> diff(A + 1, vector<vector<int>>(B + 1, vector<int>(C + 1, 0)));
    for (int i = 1; i <= mid; i++)
}

int main()
{
    cin >> A >> B >> C >> m;

    vec.resize(A, vector<vector<int>>(B, vector<int>(C, 0)));
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < C; k++)
                cin >> vec[i][j][k];

    attack.resize(m + 1, vector<int>(7));
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 7; j++)
            cin >> attack[i][j];

    return 0;
}