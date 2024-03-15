#include <iostream>
#include <cmath>
using namespace std;

bool isP(int x)
{
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int L;
    cin >> L;

    int car = 0;
    int len = 0;
    for (int i = 2;; i++)
    {
        if (isP(i))
        {
            if ((car += i) > L) break;
            else
            {
                cout << i << endl;
                len++;
            }
        }
    }
    cout << len << endl;

    return 0;
}