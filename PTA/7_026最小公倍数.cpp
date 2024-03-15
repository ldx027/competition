#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    while (cin >> a >> b)
    {
        if (b > a)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        cout << a * b / gcd(a, b) << endl;
    }

    return 0;
}