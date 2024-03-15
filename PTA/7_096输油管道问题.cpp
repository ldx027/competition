#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int x;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> x >> vec[i];
    sort(vec.begin(), vec.end());
    int mid = vec[n / 2];
    
    int rst = 0;
    for (int i = 0; i < n; i++)
    {
        rst += abs(vec[i] - mid);
    }
    cout << rst;
    return 0;
}