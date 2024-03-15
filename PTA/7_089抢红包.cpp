#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int id;
    int money;
    int cnt;
};

bool cmp(Node &a, Node &b)
{
    if (a.money != b.money) return a.money > b.money;
    if (a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.id < b.id;
}

vector<Node> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N + 1, {0, 0, 0});
    for (int i = 1; i <= N; i++) vec[i].id = i;
    
    int k, u, v;
    for (int i = 1; i <= N; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> u >> v;
            vec[u].money += v;
            vec[u].cnt++;
            vec[i].money -= v;
        }
    }

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i <= N; i++)
    {
        if (vec[i].id == 0) continue;
        printf("%d %.2f\n", vec[i].id, vec[i].money / 100.0);
    }

    return 0;
}