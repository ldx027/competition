#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    if (a < b) a ^= b ^= a ^= b;

    cout << gcd(a, b);

    return 0;
}