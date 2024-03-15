#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int sum[2] = {0, 0};
    int len[2] = {0, 0};
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        sum[i % k == 0] += i;
        len[i % k == 0]++;
    }

    printf("%.1f %.1f\n", sum[1] / double(len[1]), sum[0] / double(len[0]));
    cout << endl;

    return 0;
}