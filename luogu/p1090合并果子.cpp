#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, ans = 0;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> heap;

    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        heap.push(x);
    }

    int sum = 0;
    while (heap.size() > 1)
    {
        sum = heap.top();
        heap.pop();
        sum += heap.top();
        heap.pop();
        ans += sum;
        heap.push(sum);
    }

    cout << ans << endl;

    return 0;
}