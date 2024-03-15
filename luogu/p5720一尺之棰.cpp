#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int days = 1;
    while (n != 1)
    {
        n /= 2;
        days++;
    }

    cout << days << endl;

    return 0;
}