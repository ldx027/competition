#include <iostream>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    x--;
    int rst = 0;

    for (int i = 0; i < n; i++)
    {
        if (x < 5) rst += 250;
        x = (x + 1) % 7;
    }
    cout << rst << endl;

    return 0;
}