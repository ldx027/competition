#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;

    ll dx = 0, dy = 0;

    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x, dx += x;
        cin >> y, dy += y;
    }

    while (m--)
    {
        cin >> x >> y;
        cout << x + dx << " " << y + dy << endl;
    }
}