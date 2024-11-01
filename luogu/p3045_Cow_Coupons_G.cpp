#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

struct Node
{
    int p, c;
    bool operator<(const Node &other) const { return this->c > other.c; }
};

int main()
{
    ll n, k, m;
    cin >> n >> k >> m;

    priority_queue<Node> heap1;

    Node node;
    for (int i = 0; i < n; i++)
    {
        cin >> node.p >> node.c;
        heap1.push(node);
    }

    while (!heap1.empty())
    {
        cout << heap1.top().c << " ";
        heap1.pop();
    }
    cout << endl;

    return 0;
}