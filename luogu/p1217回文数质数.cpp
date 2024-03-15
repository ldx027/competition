#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int power(int x, int n)
{
    int rst = 1;
    for (int i = 0; i < n; i++) rst *= x;
    return rst;
}

int digit(long long x, int n)
{
    return x % power(10, n) / power(10, n - 1);
}

bool isHui(long long x)
{
    if (x == 11) return true;
    int digN = log10(x) + 1;
    if (digN % 2 == 0) return false;
    stack<int> stk;
    int i = 1;
    int d;
    for (; i <= (digN) / 2; i++)
    {
        d = digit(x, i);
        stk.push(d);
    }
    for (int i = int(digN + 1) / 2 + 1; i <= digN; i++)
    {
        d = digit(x, i);
        if (stk.empty() || stk.top() != d)
        {
            return false;
        }
        stk.pop();
    }

    return stk.empty();
}

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

vector<bool> ps;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    m = min(m, 9999999);
    ps.resize(m + 100, true);
    for (int i = 0; i < min(2, int(ps.size())); i++)
    {
        ps[i] = false;
    }

    for (int i = 2; i <= m; i++)
    {
        if (ps[i])
        {
            for (int j = 2; i * j <= m; j++)
            {
                ps[i * j] = false;
            }
        }
    }


    long long i = n + (n % 2 == 0);
    for (; i <= m; i += 2)
    {
        if (isHui(i) && ps[i])
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
