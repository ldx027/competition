#include <iostream>
using namespace std;

bool isR(int x)
{
    return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}

int main()
{
    int y, m;
    cin >> y >> m;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isR(y)) months[1] = 29;
    cout << months[m - 1] << endl;

    return 0;
}