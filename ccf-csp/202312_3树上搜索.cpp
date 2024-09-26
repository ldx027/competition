#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define ll long long
#define wtf std::cout << "wtf" << std::endl

vector<ll> vec;
vector<vector<bool>> child;
vector<int> parent;

// ll calW(vector<ll> &w, int node, unordered_set<int> &st)
// {
//     // cout << "calW";
//     // cout << node << endl;

//     w[node] = vec[node];
//     for (int i = 1; i <= vec.size(); i++)
//         if (child[node][i] && st.count(i))
//             w[node] += calW(w, i, st);
//     return w[node];
// }

bool isChild(int a, int b)
{
    while (b)
    {
        if (a == b)
            return true;
        b = parent[b];
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vec.resize(n + 1);
    child.resize(n + 1, vector<bool>(n + 1, false));
    parent.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    int x;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        child[x][i] = true;
        parent[i] = x;
    }

    while (m--)
    {
        cin >> x;

        unordered_set<int> st;
        for (int i = 1; i <= n; i++)
            st.insert(i);

        while (st.size() > 1)
        {
            // 计算权重

            vector<ll> w(n + 1);
            // for (int i = 1; i <= n; i++)
            //     if (st.count(i))
            //         w[i] = calW(w, i, st);
            // calW(w, 1, st);

            for (int i = 1; i <= n; i++)
            {
                if (st.count(i))
                {
                    w[i] += vec[i];
                    int par = parent[i];
                    while (par > 0 && st.count(par))
                    {
                        // cout << i << "par" << par << endl;
                        w[par] += vec[i];
                        par = parent[par];
                    }
                }
            }

            // 计算差值
            ll total = 0;
            for (int i = 1; i <= n; i++)
                if (st.count(i))
                    total += vec[i];

            // 选择最小项
            int minIdx = 1;
            while (!st.count(minIdx))
                minIdx++;
            for (int i = 1; i <= n; i++)
                if (st.count(i))
                    minIdx = (w[i] = abs(total - 2 * w[i])) < w[minIdx] ? i : minIdx;

            // 选择
            if (isChild(minIdx, x))
            {
                for (int i = 1; i <= n; i++)
                    if (!isChild(minIdx, i) && st.count(i))
                        st.erase(i);
            }
            else
            {
                for (int i = 1; i <= n; i++)
                    if (isChild(minIdx, i) && st.count(i))
                        st.erase(i);
            }
            // cout << "ans";
            cout << minIdx << " ";
        }
        cout << endl;
    }
}