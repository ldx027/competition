#include <iostream>
#include <cmath>
using namespace std;

int digit(int x, int n)
{
    return x % int(pow(10, n) + 0.1) / pow(10, n - 1);
}

void clear(int arr[9])
{
    for (int i = 0; i < 9; i++) arr[i] = 0;
}

bool all(int arr[9])
{
    for (int i = 0; i < 9; i++) if (arr[i] == 0) return false; return true;
}

void print(int arr[9])
{
    for (int i = 0; i < 9; i++) cout << arr[i] << " ";
}

int main()
{
    int a2, a3;
    int arr[9];
    for (int i = 123; i < 333; i++ )
    {
        clear(arr);
        a2 = 2 * i;
        a3 = 3 * i;
        for (int j = 1; j <= 3; j++)
        {
            arr[digit(i, j) - 1] = 1;
            arr[digit(a2, j) - 1] = 1;
            arr[digit(a3, j) - 1] = 1;
        }
        if (all(arr))
        {
            cout << i << " " << a2 << " " << a3 << endl;
        }
            // cout << i << " " << a2 << " " << a3 << " ";
            // print(arr);
            // cout << endl;
    }
    return 0;
}