#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &vec, int beg, int end, int x)
{
    if (beg > end) return -1;
    int mid = beg + ((end - beg) >> 1);
    int left = mid, right = mid;
    while (vec[left] == vec[mid]) left--;
    while (vec[right] == vec[mid]) right++;

    if (vec[mid] == x) return left + 2;
    else if (vec[mid] > x) return find(vec, beg, left, x);
    else if (vec[mid] < x) return find(vec, right, end, x);
}

vector<int> vec;
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
    while (m--)
    {
        cin >> x;
        cout << find(vec, 0, vec.size() - 1, x) << " ";
    }

    return 0;
}
