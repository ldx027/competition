#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int n, m;
vector<int> vec;

int main()
{
    cin >> n >> m;

    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    deque<pair<int, int>> que;
    for (int i = 0; i < m - 1; i++)
    {
        while (!que.empty() && que.back().first >= vec[i])
            que.pop_back();
        que.push_back({vec[i], i});
    }
    for (int i = m - 1; i < n; i++)
    {
        while (!que.empty() && i - que.front().second >= m)
            que.pop_front();
        while (!que.empty() && que.back().first >= vec[i])
            que.pop_back();
        que.push_back({vec[i], i});
        cout << que.front().first << endl;
    }

    return 0;
}