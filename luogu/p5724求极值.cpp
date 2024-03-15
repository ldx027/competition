#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int _max = -1000, _min = 1000;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        _min = min(_min, x);
        _max = max(_max, x);
    }

    cout << _max - _min << endl;
    
    return 0;
}