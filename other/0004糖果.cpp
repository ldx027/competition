#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << k - (n % k) << endl;

    return 0;
}