#include <iostream>
using namespace std;

int main()
{
    int m, s, t;
    cin >> m >> s >> t;

    int l1 = 0, l2 = 0;
    for (int i = 1; i <= t; i++)
    {
        l1 += 17;
        if (m >= 10) m -= 10, l2 += 60;
        else m += 4;
        l1 = max(l1, l2);
        if (l1 > s) 
        {
            cout << "Yes\n" << i << endl;
            return 0;
        }
    }
    cout << "No\n" << l1 << endl;

    return 0;
}