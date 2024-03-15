#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isP(long long x)
{
    // cout << "isP " << x << endl;
    if (x <= 1) return false;
    if (x == 2 || x ==3 || x == 5) return true;
    int n = x % 6;
    if (n % 2 == 0 || n == 3) return false;

    for (long long i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0) return false;
    }

    return true;
}

int dfs(const vector<long long> *vec, int n, int idx = 0, int have = 0, long long sum = 0)
{
    if (have == n)
    {
        return isP(sum);
    }
    if (idx == vec->size()) return 0;
    return dfs(vec, n, idx + 1, have, sum) + dfs(vec, n, idx + 1, have + 1, sum + (*vec)[idx]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    long long x;
    cin >> n >> k;
    vector<long long> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }
    cout << dfs(&vec, k);

    return 0;
}