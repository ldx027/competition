#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, int> parent;
vector<int> vec;
unordered_set<int> st;
unordered_set<int> st2;

int findPar(int x)
{
    int fr = x;
    while (parent.count(x)) x = parent[x];
    if (fr != x)
        parent[fr] = x;
    return x;
}

void merge(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (u == v) return;
    parent[v] = u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int k, u, v;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (k == 0) continue;
        cin >> u;
        st.insert(u);
        u = findPar(u);
        for (int i = 1; i < k; i++)
        {
            cin >> v;
            st.insert(v);
            merge(u, v);
        }
    }

    for (auto it = st.begin(); it != st.end(); it++) st2.insert(findPar(*it));
    cout << st.size() << " " << st2.size() << endl;
    int Q;
    cin >> Q;
    while (Q--)
    {
        cin >> u >> v;
        cout << (findPar(u) == findPar(v) ? "Y" : "N") << endl;
    }

    return 0;
}