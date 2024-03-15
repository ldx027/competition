#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> trie;
vector<bool> est;
vector<bool> repeat;
int cnt = 1;

void insert(string name)
{
    int pos = 1;
    for (int i = 0; i < name.size(); i++)
    {
        if (trie[pos][name[i] - 'a'] == 0)
            trie[pos][name[i] - 'a'] = ++cnt;
        pos = trie[pos][name[i] - 'a'];
    }
    est[pos] = true;
}

int find(string name)
{
    int pos = 1;
    for (int i = 0; i < name.size(); i++)
    {
        if (trie[pos][name[i] - 'a'] == 0) return 0;
        pos = trie[pos][name[i] - 'a'];
    }
    if (repeat[pos]) return 2;
    repeat[pos] = true;
    return est[pos];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    trie.resize(60 * n, vector<int>(26, 0));
    est.resize(60 * n, false);
    repeat.resize(60 * n, false);

    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        insert(name);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> name;
        int sta = find(name);
        if (sta == 1) cout << "OK\n";
        if (sta == 0) cout << "WRONG\n";
        if (sta == 2) cout << "REPEAT\n";
    }

    return 0;
}