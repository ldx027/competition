#include <iostream>
using namespace std;

int main()
{
    int l = 1, r = 1e9;

    int req;
    while (1)
    {
        int mid = l + ((r - l) >> 1);
        cout << mid << endl;
        cin >> req;

        if (req == 0)
            return 0;
        if (req == 1)
            r = mid - 1;
        if (req == -1)
            l = mid + 1;
    }
}