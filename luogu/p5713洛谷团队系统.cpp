#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    cout << (5 * x < 11 + 3 * x ? "Local" : "Luogu") << endl;

    return 0;
}