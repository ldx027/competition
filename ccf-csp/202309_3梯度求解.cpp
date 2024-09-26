#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

enum Type
{
    VAR,
    CONST,
    OP,
};

vector<ll> l;
vector<ll> r;
vector<ll> val;
vector<Type> type;
stack<ll> stk;
vector<ll> pos;

vector<ll> solve(int u, int x)
{
    vector<ll> rst(2, 0);
    if (type[u] == OP)
    {
        vector<ll> lchild = solve(l[u], x);
        vector<ll> rchild = solve(r[u], x);
        if (val[u] == '+')
        {
            rst[0] = ((lchild[0] + rchild[0]) % mod + mod) % mod;
            rst[1] = ((lchild[1] + rchild[1]) % mod + mod) % mod;
        }
        else if (val[u] == '-')
        {
            rst[0] = (lchild[0] - rchild[0] + mod) % mod;
            rst[1] = (lchild[1] - rchild[1] + mod) % mod;
        }
        else if (val[u] == '*')
        {
            rst[0] = (lchild[0] * rchild[0] % mod + mod) % mod;
            rst[1] = ((lchild[0] * rchild[1] % mod + mod) % mod + (lchild[1] * rchild[0]) % mod + mod) % mod;
        }
    }
    else if (type[u] == CONST)
    {
        rst[0] = (val[u] % mod + mod) % mod;
    }
    else if (type[u] == VAR)
    {
        rst[0] = (pos[val[u]] % mod + mod) % mod;
        rst[1] = (x == val[u]);
    }
    return rst;
}

vector<ll> solve2(int u, int x)
{
    vector<ll> rst(2, 0);
    if (type[u] == OP)
    {
        vector<ll> lchild = solve(l[u], x);
        vector<ll> rchild = solve(r[u], x);
        if (val[u] == '+')
        {
            rst[0] = lchild[0] + rchild[0];
            rst[1] = lchild[1] + rchild[1];
        }
        else if (val[u] == '-')
        {
            rst[0] = lchild[0] - rchild[0];
            rst[1] = lchild[1] - rchild[1];
        }
        else if (val[u] == '*')
        {
            rst[0] = lchild[0] * rchild[0];

            ll tmp1 = lchild[0] * rchild[1];
            while (tmp1 < 0)
                tmp1 += mod;
            tmp1 %= mod;

            ll tmp2 = lchild[1] * rchild[0];
            while (tmp2 < 0)
                tmp2 += mod;
            tmp2 %= mod;

            rst[1] = (tmp1 + tmp2) % mod;
        }
    }
    else if (type[u] == CONST)
    {
        rst[0] = val[u];
        while (rst[0] < 0)
            rst[0] += mod;
        rst[0] %= mod;
    }
    else if (type[u] == VAR)
    {
        rst[0] = pos[val[u]];
        while (rst[0] < 0)
            rst[0] += mod;
        rst[0] %= mod;
        rst[1] = (x == val[u]);
    }

    while (rst[0] < 0)
        rst[0] += mod;
    while (rst[1] < 0)
        rst[1] += mod;

    rst[0] %= mod;
    rst[1] %= mod;
    return rst;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    string s;
    getline(cin, s);
    getline(cin, s);

    istringstream func(s);

    ll cnt = 0;

    while (getline(func, s, ' '))
    {
        if (s.size() == 1 && s == "+" || s == "-" || s == "*")
        {
            r.push_back(stk.top());
            stk.pop();
            l.push_back(stk.top());
            stk.pop();
            val.push_back(s[0]);
            type.push_back(OP);
            stk.push(cnt++);
        }
        else if (s[0] == 'x')
        {
            ll idx = stoll(s.substr(1));
            l.push_back(-1);
            r.push_back(-1);
            val.push_back(idx - 1);
            type.push_back(VAR);
            stk.push(cnt++);
        }
        else
        {
            bool flg = true;
            int idx = 0;
            if (s[0] == '-')
                idx++, flg = false;

            ll num = 0;
            for (; idx < s.size(); idx++)
            {
                num *= 10;
                num += s[idx] - '0';
            }
            l.push_back(-1);
            r.push_back(-1);
            val.push_back(flg ? num : -num);
            type.push_back(CONST);
            stk.push(cnt++);
        }
    }

    ll root = stk.top();
    ll x;
    pos.resize(n);
    while (m--)
    {
        cin >> x;
        for (int i = 0; i < n; i++)
            cin >> pos[i];

        cout << solve(root, x - 1)[1] << endl;
    }

    return 0;
}