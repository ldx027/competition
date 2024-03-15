#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int beg, end;
};

bool cmd(Node &a, Node &b)
{
    return a.end < b.end;
}

vector<Node> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i].beg >> vec[i].end;

    sort(vec.begin(), vec.end(), cmd);

    int time = 0;
    int idx = 0;
    int total = 0;
    while (1)
    {
        while (time > vec[idx].beg && idx < n) idx++;
        if (idx == n) break;
        total++;
        time = vec[idx].end;
    }

    cout << total << endl;

    return 0;
}