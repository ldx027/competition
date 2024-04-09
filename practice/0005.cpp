#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

inline int lowbit(int x) { return x & -x; }

void add(int idx, int x)
{
    while (idx < vec.size())
    {
        vec[idx] += x;
        idx += lowbit(idx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vec.resize(N + 1, 0);
}