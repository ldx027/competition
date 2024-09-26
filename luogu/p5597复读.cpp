#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

#define ll long long
// #define test

#ifdef test
set<ll> tree;
set<ll> mintree;
#else
unordered_set<ll> tree;
unordered_set<ll> mintree;
#endif

void build(ll idx = 0)
{
    char c;
    tree.insert(idx); 
    cin >> c;

    switch (c - '0')
    {
    case 0:
        return;
    
    case 1:
    case 2:
        build(idx * 2 + 1);
        return;
    
    case 3:
        build(idx * 2 + 1);
        build(idx * 2 + 2);
        return;
    }
}

void query(ll idx = 0, ll val = -1)
{
    if (!tree.count(idx))
        return;
    
    if (val == -1)
    {
        query(2 * idx + 2, 0);
        query(2 * idx + 1, -1);
        return;
    }
    
    mintree.insert(val);
    query(2 * idx + 1, 2 * val + 1);
    query(2 * idx + 2, 2 * val + 2);
}

ll solve()
{
    ll rst = 0;
    for (auto it = mintree.begin(); it != mintree.end(); it++) 
    {
#ifdef test
        cout << "solve" << *it << " ";
#endif
        if (mintree.count(2 * *it + 1)) rst += 2;
        if (mintree.count(2 * *it + 2)) rst += 2;
    }
#ifdef test
    cout << endl;
#endif
    return rst;
}

int main()
{
    build();
    query();

#ifdef test
    for (auto it = tree.begin(); it != tree.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (auto it = mintree.begin(); it != mintree.end(); it++)
        cout << *it << " ";
    cout << endl;
#endif

#ifdef test
    cout << "ans:";
#endif

    cout << solve() + 3 << endl;

    return 0;
}