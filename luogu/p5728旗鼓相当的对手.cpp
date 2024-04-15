#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int score[3];
    int total;

    Node(int a, int b, int c)
    {
        score[0] = a;
        score[1] = b;
        score[2] = c;

        total = a + b + c;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    list<Node> lst;

    int a, b, c, total;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        total = a + b + c;

        for (auto it = lst.begin(); it != lst.end(); it++)
        {
            if (abs(it->total - total) > 10 || abs(it->score[0] - a) > 5 || abs(it->score[1] - b) > 5 || abs(it->score[2] - c) > 5)
                continue;
            cnt++;
        }
        lst.insert(lst.begin(), Node(a, b, c));
    }

    cout << cnt << endl;

    return 0;
}