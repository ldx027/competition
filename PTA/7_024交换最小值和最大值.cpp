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
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    auto it = min_element(vec.begin(), vec.end());
    int temp = vec[0];
    vec[0] = *it;
    *it = temp;

    it = max_element(vec.begin(), vec.end());
    temp = vec[vec.size() - 1];
    vec[vec.size() - 1] = *it;
    *it = temp;

    for (int i = 0; i < n; i++) cout << vec[i] << " ";

    return 0;
}