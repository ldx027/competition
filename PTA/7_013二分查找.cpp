#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int> &vec, int x, int beg, int end)
{
    if (end < beg) return -1;
    int mid = beg + ((end - beg) >> 1);
    int left = mid, right = mid;
    while (left - 1 >= beg && vec[left - 1] == vec[mid]) left--;
    while (right + 1 <= end && vec[right + 1] == vec[mid]) right++;

    if (vec[mid] == x) return left;
    if (vec[mid] > x) return find(vec, x, beg, left - 1);
    if (vec[mid] < x) return find(vec, x, right + 1, end);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int n, m, x;
    while (cin >> n)
    {
        bool flg = 0;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        sort(vec.begin(), vec.end());
        cout << vec[0];
        for (int i = 1; i < n; i++) cout << " " << vec[i];
        cout << endl;
        
        cin >> m;
        while (m--)
        {
            cin >> x;
            if (flg) cout << " ";
            cout << find(vec, x, 0, n - 1) + 1;
            flg = 1;
        }
        cout << endl;
    }

    return 0;
}