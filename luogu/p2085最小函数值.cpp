#include <iostream>
#include <queue>
 #include <stack>
using namespace std;

int main()
{
    priority_queue<int> heap;

    int n, m;
    cin >> n >> m;

    vector<bool> need(n, true);
    vector<vector<int>> vec(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> vec[i][j];
        

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!need[j])
                continue;
            int y = i * i * vec[j][0] + i * vec[j][1] + vec[j][2];
            // cout << i << " " << j << " " << y << endl;
            if (i == 1 || heap.size() < m || y <= heap.top())
                heap.push(y);
            else
                need[j] = false;

            while (heap.size() > m)
                heap.pop();
        }
    }

    stack<int> stk;
    for (int i = 0; i < m; i++)
    {
        stk.push(heap.top());
        heap.pop();
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}