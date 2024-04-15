#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int a = 0, b = 1;

    int state = -1;

    while (N--)
    {
        if (state == 1 && a == 1)
        {
            b++;
            state = -1;
            continue;
        }
        if (state == -1 && b == 1)
        {
            a++;
            state = 1;
            continue;
        }

        b += state;
        a -= state;
    }

    cout << a << "/" << b << endl;

    return 0;
}