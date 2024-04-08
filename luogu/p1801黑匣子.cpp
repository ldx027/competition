#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<int> num(m);
    vector<int> get(n);

    for (int i = 0; i < m; i++) cin >> num[i];
    for (int i = 0; i < n; i++) cin >> get[i];

    priority_queue<int, vector<int>, greater<int>> sHeap;
    priority_queue<int, vector<int>, less<int>> bHeap;

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        while (idx < get[i])
        {
            bHeap.push(num[idx]);
            sHeap.push(bHeap.top());
            bHeap.pop();
            idx++;
        }

        cout << sHeap.top() << endl;
        bHeap.push(sHeap.top());
        sHeap.pop();
    }

    return 0;
}