#include <iostream>
#include <vector>
using namespace std;

bool isBea(vector<int> vec)
{
    int cur = 0;
    while (cur < vec.size())
    {
        int n = vec[cur++];
        cur += n;
    }
    return cur == vec.size();
}

void func()
{

}

vector<int> vec;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        dp.clear();
        vec.resize(n + 1);
        dp.resize(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) cin >> vec[i];
    }

    return 0;
}