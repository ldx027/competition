#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return a + b > b + a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < n; i++) cout << vec[i];

    return 0;
}