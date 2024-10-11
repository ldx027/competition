#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> pos;
vector<vector<int>> posIdx;
vector<int> buf;
vector<vector<int>> diff, sum;

void show(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void show(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
        show(vec[i]);
    cout << endl;
}

int main()
{
    cin >> n;

    pos.resize(n, vector<int>(4));
    posIdx.resize(n, vector<int>(4));
    buf.resize(n << 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> pos[i][j], buf[(i << 2) + j] = pos[i][j];
        
        int tmp;
        if (pos[i][0] > pos[i][2])
        {
            tmp = pos[i][0];
            pos[i][0] = pos[i][2];
            pos[i][2] = tmp;
        }
        if (pos[i][1] > pos[i][3])
        {
            tmp = pos[i][1];
            pos[i][1] = pos[i][3];
            pos[i][3] = tmp;
        }
    }

    sort(buf.begin(), buf.end());
    buf.erase(unique(buf.begin(), buf.end()), buf.end());

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            posIdx[i][j] = lower_bound(buf.begin(), buf.end(), pos[i][j]) - buf.begin() + 1;

    diff.resize(buf.size() + 1, vector<int>(buf.size() + 1, 0));
    for (int i = 0; i < n; i++)
    {
        diff[posIdx[i][0]][posIdx[i][1]]++;
        diff[posIdx[i][0]][posIdx[i][3]]--;
        diff[posIdx[i][2]][posIdx[i][1]]--;
        diff[posIdx[i][2]][posIdx[i][3]]++;
    }

    sum.resize(buf.size() + 1, vector<int>(buf.size() + 1, 0));
    for (int i = 1; i < sum.size(); i++)
        for (int j = 1; j < sum.size(); j++)
            sum[i][j] = diff[i][j] + sum[i - 1][j - 1] - sum[i][j - 1] - sum[i - 1][j];
    
    show(sum);

    return 0;
}