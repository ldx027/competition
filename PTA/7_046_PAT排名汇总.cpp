#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    string id;
    int sc;
    int nativeR;
    int rank;
    int kd;
    void show()
    {
        cout << id << " " rank << " " << 
    }
};

bool cmd(Node &a, Node &b)
{
    return a.sc > b.sc || (a.sc == b.sc && a.id < b.id);
}

vector<Node> vec(3e4 + 10);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int total = 0;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int k;
        cin >> k;
        total += k;
        for (int j = 1; j <= k; j++)
        {
            cin >> vec[total].id;
            cin >> vec[total].sc;
            vec[total].nativeR = j;
            vec[total++].kd = i;
        }
    }

    sort(vec.begin(), vec.end(), cmd);
    vec[0].rank = 1;
    for (int i = 1; i < total; i++)
    {
        if (vec[i].sc == vec[i - 1].sc) vec[i].rank = vec[i - 1].rank;
        else vec[i].rank = i + 1;
    }
}