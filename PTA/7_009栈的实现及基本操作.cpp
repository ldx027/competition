#include <iostream>
#include <queue>
using namespace std;

queue<int> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int cmd, d;

    while (n--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> d;
            que.push(d);
        }
        else
        {
            if (que.empty())
            {
                cout << "invalid" << endl;
            }
            else
            {
                cout << que.front() << endl;
                que.pop();
            }
        }
    }

    return 0;
}