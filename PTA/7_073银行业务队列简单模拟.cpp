#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int x;
    cin >> N;
    queue<int> A, B;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x % 2) A.push(x);
        else B.push(x);
    }

    bool flg = 0;
    while (!A.empty() || !B.empty())
    {
        for (int i = 0; !A.empty() && i < 2; i++)
        {
            if (flg) cout << " ";
            cout << A.front();
            A.pop();
            flg = true;
        }
        if (!B.empty())
        {
            if (flg) cout << " ";
            cout << B.front();
            B.pop();
        }
    }

    return 0;
}