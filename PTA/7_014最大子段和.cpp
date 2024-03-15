#include <iostream>
#include <vector>
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

    int sum = 0, x = 0;

    for (int i = 0; i < n; i++)
    {
        if (x <= 0) x = vec[i];
        else if (x > 0) x += vec[i];
        if (x > sum) sum = x;
    }
    
    cout << sum << endl;
    return 0;
}