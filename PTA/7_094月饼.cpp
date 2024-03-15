#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    double kc;
    double sj;
};

bool cmd(Node &a, Node &b)
{
    return a.sj >= b.sj;
}

vector<Node> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, D;
    double x;
    cin >> N >> D; 
    vec.resize(N);
    for (int i = 0; i < N; i++) cin >> vec[i].kc;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        vec[i].sj = x / vec[i].kc;
    }

    sort(vec.begin(), vec.end(), cmd);

    double rst = 0;
    int idx = 0;
    while (D > 0 && idx < N)
    {
        double num = min(double(D), vec[idx].kc);
        rst += num * vec[idx++].sj;
        D -= num;
    }

    printf("%.2f", rst);

    return 0;
}