#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec = {1, 2, 3};

    cout << lower_bound(vec.begin(), vec.end(), 4) - vec.begin() << endl;

    return 0;
}