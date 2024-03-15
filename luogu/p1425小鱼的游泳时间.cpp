#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int min = (c - a) * 60 + d - b;
    printf("%d %d", min / 60, min % 60);

    return 0;
}