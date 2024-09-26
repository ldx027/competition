#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void solve1()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    int x;
    unordered_set<int> st;
    for (int i = 0; i < m; i++)
        cin >> x, st.insert(x);

    for (int i = 0; i < n; i++)
        if (st.count(vec[i]))
            cout << vec[i] << " ";
    
    return;
}

bool binFind(int l, int r, int val, vector<int> &vec)
{
    if (l > r)
        return false;

    int mid = l + ((r - l) >> 1);
    
    if (vec[mid] == val)
        return true;
    if (vec[mid] < val)
        return binFind(mid + 1, r, val, vec);
    else
        return binFind(l, mid - 1, val, vec);
}

void solve2()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec1(n);
    vector<int> vec2(m);

    for (int i = 0; i < n; i++)
        cin >> vec1[i];
    
    for (int i = 0; i < m; i++)
        cin >> vec2[i];

    sort(vec2.begin(), vec2.end());

    for (int i = 0; i < n; i++)
    {
        if (binFind(0, m - 1, vec1[i], vec2))
            cout << vec1[i] << " ";
    }
}

int main()
{
    solve2();
    return 0;
}