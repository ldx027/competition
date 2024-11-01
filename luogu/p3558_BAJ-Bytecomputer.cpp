#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

int n;
vector<int> vec;
vector<vector<int>> dp;

int main()
{
    cin >> n;

    vec.resize(n + 1, 0);
    dp.resize(n + 1, vector<int>(3));

    for (int i = 1; i <= n; i++)
        cin >> vec[i];
    
    for (int i = 1; i <= n; i++)
    {
        if (vec[i] == -1)
        {
            dp[i][0] = 0;

            if ()
        }
    }
}