#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    n = 1 << n;
    queue<pair<int, int>> que;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        que.push({x, i});
    }

    while (que.size() > 2)
    {
        pair<int, int> p1 = que.front();
        que.pop();
        pair<int, int> p2 = que.front();
        que.pop();
        que.push(p1.first > p2.first ? p1 : p2);
    }
    pair<int, int> p1 = que.front();
    que.pop();
    pair<int, int> p2 = que.front();
    cout << (p1.first < p2.first ? p1.second : p2.second) << endl;

    return 0;
}