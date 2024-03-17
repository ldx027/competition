#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int base = 233;
const int mod = 1e9 + 7;

int getHash(string str)
{
    int rst = 0;
    for (int i = 0; i < str.size(); i++)
        rst = ((long long)rst * base + str[i]) % mod + 131; 
    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vec(N);

    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        vec[i] = getHash(str);
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || vec[i] != vec[i - 1]) ans++;
    }

    cout << ans << endl;

    return 0;
}