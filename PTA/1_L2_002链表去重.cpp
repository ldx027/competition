#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

struct Node
{
    int adrs;
    int val;
    int next;
    Node() { next = -1; }
    Node(int _adrs, int _val, int _next) : adrs(_adrs), val(_val), next(_next) {}

    void show()
    {
        string str1 = to_string(adrs);
        while (str1.size() < 5) str1.insert(str1.begin(), '0');
        string str2 = to_string(next);
        if (next > -1) while (str2.size() < 5) str2.insert(str2.begin(), '0');
        cout << str1 << " " << val << " " << str2 << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, N;
    cin >> L >> N;

    vector<Node> mem(1e6 + 3);

    int adrs, val, next;
    for (int i = 0; i < N; i++)
    {
        cin >> adrs >> val >> next;
        mem[adrs] = Node(adrs, val, next);
    }

    vector<bool> have(1e4 + 10, false);
    list<Node> lst1;
    list<Node> lst2;

    while (L != -1)
    {
        if (!have[abs(mem[L].val)])
        {
            lst1.push_back(mem[L]);
            have[abs(mem[L].val)] = true;
        }
        else
        {
            lst2.push_back(mem[L]);
        }
        L = mem[L].next;
    }

    while (!lst1.empty())
    {
        if (lst1.size() == 1) lst1.begin()->next = -1;
        else lst1.begin()->next = (++lst1.begin())->adrs;
        lst1.begin()->show();
        lst1.pop_front();
    }
    while (!lst2.empty())
    {
        if (lst2.size() == 1) lst2.begin()->next = -1;
        else lst2.begin()->next = (++lst2.begin())->adrs;
        lst2.begin()->show();
        lst2.pop_front();
    }

    return 0;
}