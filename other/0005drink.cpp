#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }

    int sidx = 0;
    int bidx = vec.size() - 1;
    while (vec[sidx] == 0) sidx++;
    while (vec[bidx] == 0) bidx--;

    if (bidx - sidx <= 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << bidx - sidx + 1 << endl;

    return 0;
}