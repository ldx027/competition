#include <iostream>
#include <string>
#include <vector>
using namespace std;

int change(char c)
{
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
}

struct Trie
{
    int cnt;
    vector<vector<int>> vec;
    vector<bool> vst;

    Trie(int max)
    {
        cnt = 1;
        vec.resize(max, vector<int>(62, 0));
        vst.resize(max, 0);
    }

    void insert(string str)
    {
        int cur = 1;
        for (auto it = str.begin(); it != str.end(); it++)
        {
            int idx = change(*it);
            if (vec[cur][idx] == 0) vec[cur][idx] = ++cnt;
            cur = vec[cur][idx];
        }
        vst[cur] = true;
    }

    bool find(string str)
    {
        int cur = 1;
        for (auto it = str.begin(); it != str.end(); it++)
        {
            int idx = change(*it);
            if (vec[cur][idx] == 0) return false;
        }
        return vst[cur];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Trie trie(N * 80);

    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        trie.insert(str);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> str;
        cout << trie.find(str) << endl;
    }

    return 0;
}