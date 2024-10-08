#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    vector<int> buf = vec;
    sort(buf.begin(), buf.end());

    for (int i = 0; i < n; i++)
        vec[i] = lower_bound(buf.begin(), buf.end(), vec[i]) - buf.begin() + 1;
    
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}