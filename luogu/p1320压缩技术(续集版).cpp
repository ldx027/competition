#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<char> vec(5e4);
    int i = 0;
    while (cin >> vec[i++]);

    cout << (int)sqrt(i);

    int kind = 0;
    int cnt = 0;

    for (int j = 0; j < i; j++)
    {
        if (vec[j] - '0' == kind)
            cnt++;
        else
        {
            cout << " " << cnt;
            cnt = 1;
            kind = !kind;
        }
    }

    return 0;
}