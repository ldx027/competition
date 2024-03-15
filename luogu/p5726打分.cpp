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

    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    int sum = -max - min;
    for (int i = 0; i < n; i++) sum += vec[i];

    printf("%.2f", sum / (n - 2.));

    return 0;
}