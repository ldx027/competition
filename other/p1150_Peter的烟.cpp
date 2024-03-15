#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    cout << n + (n - 1) / (k - 1) << endl;

    return 0;
}