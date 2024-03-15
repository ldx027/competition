#include <iostream>
using namespace std;

int abs(int x)
{
    return x > 0 ? x : -x;
}

int main()
{
    char c;
    cin >> c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (abs(j - 2) > i)
            {
                cout << " ";
            }
            else
            {
                cout << c;
            }
        }
    cout << endl;
    }
}