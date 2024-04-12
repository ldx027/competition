#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define maxN 1e3

int change(char c)
{
    if (c >= 'a' && c <='z') return c - 'a';
    if (c >= 'A' && c <='Z') return c - 'A' + 26;
    if (c >= '0' && c <='9') return c - '0' + 52;
}

int cnt = 0;
vector<vector<int>> trie(maxN, vector<int>(62, 0));
vector<bool> vst(maxN, false);

void add(string str)
{
    int cur = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (trie[cur][change(str[i])] == 0) trie[cur][change(str[i])] = ++cnt;
        cur = trie[cur][change(str[i])];
    }
    vst[cur] = true;
}

bool find(string str)
{
    int cur = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (trie[cur][change(str[i])] == 0) return false;
        cur = trie[cur][change(str[i])];
    }
    return vst[cur];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    add("abc");
    cout << find("ab") << find("abc") << find("dcba");

    return 0;
}
