#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> func3(vector<vector<char>> vec, int n)
{
    vector<vector<char>> rst(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j  = 0; j < n; j++)
        {
            rst[i][j] = vec[n - 1 - i][i];
        }
    }

    return rst;
}

vector<vector<char>> func2(vector<vector<char>> vec, int n)
{
    vector<vector<char>> rst(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rst[i][j] = vec[n - 1 - i][n - 1 - j];
        }
    }

    return rst;
}

vector<vector<char>> func1(vector<vector<char>> vec, int n)
{
    vector<vector<char>> rst(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rst[i][j] = vec[n - 1 - j][i];
        }
    }

    return rst;
}

vector<vector<char>> func4(vector<vector<char>> vec, int n)
{
    vector<vector<char>> rst(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rst[i][j] = vec[i][n - 1 - j];
        }
    }

    return rst;
}

vector<vector<char>> func5(vector<vector<char>> vec, int n)
{
    vector<vector<char>> rst(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rst[i][j] = vec[n - 1 - i][j];
        }
    }

    return rst;
}


vector<vector<char>> func6(vector<vector<char>> vec, int n)
{
    return vec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> vec(n, vector<char>(n));
    vector<vector<char>> rst(n, vector<char>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> vec[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> rst[i][j];

    if (rst == func1(vec, n))
    {
        cout << 1 << endl;
        return 0;
    }
    if (rst == func2(vec, n))
    {
        cout << 2 << endl;
        return 0;
    }
    if (rst == func3(vec, n))
    {
        cout << 3 << endl;
        return 0;
    }
    if (rst == func4(vec, n))
    {
        cout << 4 << endl;
        return 0;
    }
    if (rst == func1(func5(vec, n), n))
    {
        cout << 5 << endl;
        return 0;
    }
    if (rst == func2(func5(vec, n), n))
    {
        cout << 5 << endl;
        return 0;
    }
    if (rst == func3(func5(vec, n), n))
    {
        cout << 5 << endl;
        return 0;
    }
    if (rst == func6(vec, n))
    {
        cout << 6 << endl;
        return 0;
    }
    cout << 7 << endl;
    return 0;
}
