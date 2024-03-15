#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

bool isP(long long x)
{
    if (x <= 1) return false;
    if (x == 2 || x == 3 || x ==5) return true;
    int n = x % 6;
    if (n == 2 || n == 4 || n == 4 || n == 0) return false;

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0) return false;
    }

    return true;

}

int len(long long x)
{
    queue<pair<long long, int>> que;
    que.push({x, 0});
    int rst = 0;
    while (!que.empty())
    {
        if (isP(que.front().first))
        {
            rst = que.front().second;
        }
        else
        {
            for (long long  i = 2; i <= sqrt(que.front().first); i++)
            {
                que.push({i, que.front().second + 1});
            }
        }
        que.pop();
    }
    return rst;
}

int main()
{
    long long Q;
    cin >> Q;
    for (long long i = 2; i < Q; i++)
    {
        if (Q % i == 0)
        {
            cout << i << "len" << len(i) << endl;
            if (len(i) % 2 == 1)
            {
                cout << 1 << endl << i << endl;
                return 0;
            }
        }
    }
    cout << 2 << endl;

    return 0;
}
