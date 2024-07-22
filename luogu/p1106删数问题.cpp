#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    int k;

    cin >> n >> k;

    while (k--)
    {
        int pos = 0;
        while (1)
        {
            if (pos == n.size() - 1 || n[pos] > n[pos + 1])
                break;
            ++pos;
        }
        n = n.erase(pos, 1);
    }

    int pos = 0;
    while (pos < n.size() && n[pos] == '0') pos++;
    n = n.erase(0, pos);

    if (n.size() == 0) n = "0";

    cout << n << endl;

    return 0;
}