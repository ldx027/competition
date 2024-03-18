#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int binFind(int x)
{
    int beg = 0, end = vec.size() - 1, mid;
    int left, right;

    while (beg <= end)
    {
        mid = beg + ((end - beg) >> 1);
        left = right = mid;
        while (left - 1 >= beg && vec[left - 1] == vec[mid]) left--;
        while (right + 1 <= end && vec[right + 1] == vec[mid]) right++;

        if (vec[left] == x) return left;
        if (vec[mid] > x) end = left - 1;
        else beg = right + 1;
    }

    return -2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cout << binFind(x) + 1 << " ";
    }

    return 0;
}