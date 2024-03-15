#include <iostream>
#include <cmath>
using namespace std;

bool canSquare(long long x)
{
    return (pow(int(sqrt(x)), 2) == x);;
}

int main()
{
    long long t, n;
    long long sum;
    long long x;

    cin >> t;

    for (long long i = 0; i < t; i++)
    {
        cin >> n;
        sum = 0;
        for (long long j = 0; j < n; j++)
        {
            cin >> x;
            sum += x;
        }
        cout << (canSquare(sum) ? "YES" : "NO") << endl;
    }

    return 0;
}