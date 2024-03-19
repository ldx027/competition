#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int lowbit(int x) { return x & -x; }

void add(int idx, int k)
{
    while (idx < vec.size())
    {
        vec[idx] += k;
        idx += lowbit(idx);
    }
}

int sum(int idx)
{
    int rst = 0;
    while (idx > 0)
    {
        rst += vec[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vec.resize(N + 1, 0);

    int x;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        add(i, x);
    }
    
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        if (a == 1) add(b, c);
        else if (a == 2) cout << sum(c) - sum(b - 1) << endl;
    }

    return 0;
}