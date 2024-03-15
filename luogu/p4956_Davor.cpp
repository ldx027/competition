#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    N /= 52;

    int k;
    for (k = 1; (N - 21 * k) % 7 != 0 || (N - 21 * k) > 700; k++);
    cout << (N - 21 * k) / 7 << endl << k << endl;

    return 0;
}