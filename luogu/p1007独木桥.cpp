#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define ull unsigned ll
#define inf 0x7f7f7f7f

int main()
{
    ull L, N;
    cin >> L >> N;

    ull Min = 0, Max = 0;

    ull x;
    for (ull i = 0; i < N; i++)
    {
        cin >> x;

        Min = max(Min, min(x, L + 1 - x));
        Max = max(Max, max(x, L + 1 - x));
    }

    cout << Min << " " << Max << endl;

    return 0;
}