#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    if (a == b) return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int gcd(int a, int b)
{
    if (a < b) swap(&a, &b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int n = 0;
    for (int i = 1; i <= 2020; i++)
    {
        for (int j = 1; j <= 2020; j++)
        {
            if (gcd(i, j) == 1)
            {
                n++;
            }
        }
    }
    cout << n;
    return 0;
}