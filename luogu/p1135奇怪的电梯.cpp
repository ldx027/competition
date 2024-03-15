#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, A, B;
    cin >> N >> A >> B;
    A--; B--;

    vector<int> vec(N);
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    ans[A] = 0;

    queue<int> que;
    que.push(A);

    while (ans[B] == -1 && !que.empty())
    {
        int now = que.front();
        if (now - vec[now] >= 0 && ans[now - vec[now]] == -1)
        {
            que.push(now - vec[now]);
            ans[now - vec[now]] = ans[now] + 1;
        }
        if (now + vec[now] < N && ans[now + vec[now]] == -1)
        {
            que.push(now + vec[now]);
            ans[now + vec[now]] = ans[now] + 1;
        }
        que.pop();
    }

    cout << ans[B] << endl;

    return 0;

}