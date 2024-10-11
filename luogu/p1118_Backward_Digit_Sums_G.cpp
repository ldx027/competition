#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// #define debug

int n, goal;
vector<int> base;
vector<int> vec;
vector<int> cur;
unordered_set<int> st;
bool have = false;

void dfs(int s, int t)
{
    if (have)
        return;
    int total = 0;
    for (int i = 0; i < s; i++)
        total += cur[i] * base[i];
    
    if (total > goal)
        return;

    // cout << s << " " << t << endl;
    if (s == t && total == goal)
    {
        for (int i = 0; i < cur.size(); i++)
            cout << cur[i] << " ";
        cout << endl;
        have = true;
        return;
    }

    for (int i = 0; i < t; i++)
    {
        if (st.count(i))
            continue;
        
        st.insert(i);
        cur[s] = vec[i];
        dfs(s + 1, t);
        st.erase(i);
    }
}

int main()
{
    cin >> n >> goal;

    base.resize(n, 0);
    base[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j > 0; j--)
            base[j] += base[j - 1];
    }

    vec.resize(n);
    cur.resize(n);
    for (int i = 0; i < n; i++)
        vec[i] = i + 1;
    
    dfs(0, n);

    return 0;
}