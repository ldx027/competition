#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool smaller(string a, string b)
{
    return (a <= b) || (a == b && *a.rbegin() <= *b.rbegin());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), smaller);
    // for_each(vec.begin(), vec.end(), show);

    return 0;
}