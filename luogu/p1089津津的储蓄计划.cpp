#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cur = 0;
    int store = 0;

    int x;
    for (int i = 1; i <= 12; i++)
    {
        cur += 300;

        cin >> x;
        cur -= x;        

        if (cur < 0)
        {
            cout << -i;
            return 0;
        }

        store += cur / 100 * 100;
        cur %= 100;
    }

    cout << int(store * 1.2) + cur << endl;

    return 0;
}