#include <iostream>
#include <cmath>
using namespace std;

bool isS(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i < n; i++)
    {
        if (isS(i) && n % i == 0 && isS(n / i))
        {
            cout << n / i << endl;
            return 0;
        }
    }
    
    return 0;
}