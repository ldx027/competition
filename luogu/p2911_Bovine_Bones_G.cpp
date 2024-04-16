#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int Max = 0;
    vector<int> vec(100, 0);

    for (int i = 1; i <= s1; i++)
    for (int j = 1; j <= s2; j++)
    for (int k = 1; k <= s3; k++)
    Max = max(Max, ++vec[i + j + k]);

    for (int i = 1; i < 100; i++)
    {
        if (vec[i] == Max)
        {
            cout << i << endl;
            return 0;
        }
    }
}