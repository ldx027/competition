#include <iostream>
using namespace std;

bool isR(int x)
{
    return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}

int main()
{
    int x;
    cin >> x;
    cout << (isR(x) ? 1 : 0) << endl;

    return 0;
}