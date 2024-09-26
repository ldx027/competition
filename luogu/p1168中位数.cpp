#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<int>> s;
    priority_queue<int, vector<int>, greater<int>> b;

    int n;
    cin >> n;

    int x;
    cin >> x;

    s.push(x);
    cout << x << endl;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x > s.top()) b.push(x);
        else s.push(x);
        
        while (abs((int)s.size() - (int)b.size()) > 1)
        {
            if (s.size() > b.size())
            {
                b.push(s.top());
                s.pop();
            }
            else
            {
                s.push(b.top());
                b.pop();
            }
        }

        if (i % 2 == 0)
            cout << (s.size() > b.size() ? s.top() : b.top()) << endl;
    }

    return 0;
}