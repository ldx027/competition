#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    long long val, height;
    bool operator<(const Node &node) const
    {
        return node.val == val ? height > node.height : val > node.val;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    priority_queue<Node> heap;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        heap.push({x, 1});
    }

    long long ans = 0, height = 0;

    while ((heap.size() - 1) % (k - 1) != 0) heap.push({0, 1});
    while (heap.size() >= k)
    {
        long long w = 0, h = -1;
        for (int i = 0; i < k; i++)
        {
            Node cur = heap.top();
            heap.pop();
            w += cur.val;
            h = max(h, cur.height);
        }
        ans += w;
        heap.push({w, h + 1});
    }

    cout << ans << endl;
    cout << heap.top().height - 1 << endl;

    return 0;
}