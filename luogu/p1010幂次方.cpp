#include <iostream>
using namespace std;

void dfs(int x)
{
    for (int i = 15; i >= 0; i--)
    {
        if (x >> i & 1)
        {
            if (i == 0)
                cout << "2(0)";
            else if (i == 1)
                cout << "2";
            else
            {
                cout << "2(";
                dfs(i);
                cout << ")";
            }

            x -= 1 << i;
            if (x)
                cout << "+";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    cin >> x;

    dfs(x);

    return 0;
}