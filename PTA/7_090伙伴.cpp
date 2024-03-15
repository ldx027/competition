#include <iostream>
#include <vector>
using namespace std;

vector<long long> A(101, 0);
vector<long long> B(101, 0);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, m;
    int x;
    cin >> n >> m;

    for (long long i = 0; i < n; i++)
    {
        cin >> x;
        A[x]++;
    }
    for (long long i = 0; i < m; i++)
    {
        cin >> x;
        B[x]++;
    }

    long long rst = 0;
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (i + j > 100) break;
            rst += A[i] * B[j] * B[i + j] * (i + j);
        }
    }
    while (rst < 0);

    cout << rst << endl;

    return 0;
}
