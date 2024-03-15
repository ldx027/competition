#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define maxN (3e6 + 10)

int char2num(char c)
{
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
}

int cnt = 1;
vector<vector<int>> trie;
vector<bool> est;
vector<int> pre;

void insert(string str)
{
    int max = 0;
    int pos = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (trie[pos][char2num(str[i])] == 0)
            trie[pos][char2num(str[i])] = ++cnt;
        pos = trie[pos][char2num(str[i])];
        pre[pos]++;
    }
    est[pos] = true;
}

int find(string str)
{
    int pos = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (trie[pos][char2num(str[i])] == 0) return 0;
        pos = trie[pos][char2num(str[i])];
    }
    return pre[pos];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    trie.resize(maxN, vector<int>(62, 0));
    est.resize(maxN, 0);
    pre.resize(maxN, 0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        string str;
        cin >> n >> q;

        for (int i = 0; i <= cnt; i++) pre[i] = 0;
        for (int i = 0; i <= cnt; i++) trie[i] = vector<int>(62, 0);
        for (int i = 0; i <= cnt; i++) est[i] = 0;
        cnt = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> str;
            insert(str);
        }
        for (int i = 0; i < q; i++)
        {
            cin >> str;
            cout << find(str) << endl;
        }
    }

    return 0;
}