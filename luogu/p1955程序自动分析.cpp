#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> frd;

int findFrd(int u) { return frd[u] ? frd[u] = findFrd(frd[u]) : u; }
bool isFrd(int u, int v) { return findFrd(u) == findFrd(v); }
void mkFrd(int u, int v)
{
    u = findFrd(u), v = findFrd(v);
    if (u != v) frd[u] = v;
}

struct Item
{
    int u, v, e;
};
bool cmp(Item a, Item b) { return a.e > b.e; }

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        frd.clear();

        int n, m;
        cin >> n;
        vector<Item> ipt(n);
        vector<int> buff(n << 1);
        for (int i = 0; i < n; i++)
        {
            cin >> ipt[i].u >> ipt[i].v >> ipt[i].e;
            buff[i << 1] = ipt[i].u;
            buff[i << 1 | 1] = ipt[i].v;
        }
        sort(ipt.begin(), ipt.end(), cmp);
        sort(buff.begin(), buff.end());
        buff.erase(unique(buff.begin(), buff.end()), buff.end());
        m = buff.size();
        frd.resize(m + 1);
        for (int i = 0; i < n; i++)
        {
            ipt[i].u = lower_bound(buff.begin(), buff.end(), ipt[i].u) - buff.begin() + 1;
            ipt[i].v = lower_bound(buff.begin(), buff.end(), ipt[i].v) - buff.begin() + 1;
        }

        bool flg = true;
        for (int i = 0; i < n; i++) 
        {
            int u = ipt[i].u, v = ipt[i].v;

            if (ipt[i].e)
                mkFrd(u, v);
            else
            {
                if (isFrd(u, v))
                    flg = false;
            }
        }

        cout << (flg ? "YES" : "NO") << endl;
    }

    return 0;
}