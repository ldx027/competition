#include <iostream>
using namespace std;

int main()
{
    int x;
    int idx = 0;

    while (++idx)
    {
        cin >> x;
        if (x == 250) break;
    }
    cout << idx << endl;

    return 0;
}