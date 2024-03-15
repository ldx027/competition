#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int func(vector<vector<int>> &vec, int x)
{
    int rst = 0;
    if (x >= 1 && x <= 3)
        for (int i = 0; i < 3; i++)
            rst += vec[x - 1][i];
    else if (x >= 4 && x <= 6)
        for (int i = 0; i < 3; i++)
            rst += vec[i][x - 4];
    else if (x == 7)
        for (int i = 0; i < 3; i++)
            rst += vec[i][i];
    else if (x == 8)
        for (int i = 0; i < 3; i++)
            rst += vec[2 - i][i];

    return rst;
}

int arr[] = {10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};

vector<vector<int>> vec(3, vector<int>(3));
unordered_set<int> st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 9; i++)
        st.insert(i);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> vec[i][j];
            st.erase(vec[i][j]);
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (vec[i][j] == 0)
                vec[i][j] = *st.begin();
        }

    int x, y;
    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        x--, y--;
        cout << vec[x][y] << endl;
    }

    int w;
    cin >> w;
    cout << arr[func(vec, w) - 6] << endl;

    return 0;
}