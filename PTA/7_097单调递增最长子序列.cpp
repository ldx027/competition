#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vec.resize(n);
    dp.resize(n, 1);
    for (int i = 0; i < n; i++) cin >> vec[i];
    for (int i = 1; i < n; i++) for (int j = 0; j < i; j++)
    {
        if (vec[i] > vec[j])
        {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}