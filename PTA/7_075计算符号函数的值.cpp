#include <iostream>
using namespace std;

int sign(int x)
{
    if (x > 0) return 1;
    if (x == 0) return 0;
    return -1;
}

int main()
{
    int x;
    cin >> x;
    printf("sign(%d) = %d", x, sign(x));

    return 0;
}