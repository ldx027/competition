#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define mod 998244353

struct Matrix
{
    vector<vector<ll>> vec;
    Matrix()
    {
        vec.resize(2, vector<ll>(2, 0));
        vec[0][0] = vec[1][1] = 1;
    }
    Matrix(ll a, ll b, ll c, ll d)
    {
        vec.resize(2, vector<ll>(2));
        vec[0][0] = a;
        vec[0][1] = b;
        vec[1][0] = c;
        vec[1][1] = d;
        for (int i = 0; i < 4; i++)
            vec[i / 2][i % 2] %= mod;
    }

    Matrix mul(const Matrix &other) 
    {
        Matrix rst;
        rst.vec[0][0] = vec[0][0] * other.vec[0][0] + vec[0][1] * other.vec[1][0];
        rst.vec[0][1] = vec[0][0] * other.vec[0][1] + vec[0][1] * other.vec[1][1];
        rst.vec[1][0] = vec[1][0] * other.vec[0][0] + vec[1][1] * other.vec[1][0];
        rst.vec[1][1] = vec[1][0] * other.vec[0][1] + vec[1][1] * other.vec[1][1];
        for (int i = 0; i < 4; i++e        return rst;
    }

    void show()
    {
        for (int i = 0; i < 4; i++)
            cout << vec[i / 2][i % 2] << " ";
        cout << endl;
    }
};

vector<short> cmd;
vector<Matrix> vec;

int main()
{
    int n, m;
    cin >> n >> m;

    ll a, b, c, d;

    cmd.resize(n + 1);
    vec.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> cmd[i];
        if (cmd[i] != 3)
        {
            cin >> a >> b >> c >> d;
            vec[i] = Matrix(a, b, c, d);
        }
    }

    ll v, l, r;
    while (m--)
    {
        cin >> v;
        if (v == 1)
        {
            cin >> l >> cmd[l];
            if (cmd[l] != 3)
            {
                cin >> a >> b >> c >> d;
                vec[l] = Matrix(a, b, c, d);
            }
        }
        else
        {
            cin >> l >> r;
            deque<Matrix> que;
            stack<int> stk;

            for (int i = l; i <= r; i++)
            {
                if (cmd[i] == 1)
                {
                    que.push_front(vec[i]);
                    stk.push(1);
                }
                else if (cmd[i] == 2)
                {
                    que.push_back(vec[i]);
                    stk.push(2);
                }
                else
                {
                    if (stk.empty())
                        continue;

                    if (stk.top() == 1)
                        que.pop_front();
                    else
                        que.pop_back();
                    stk.pop();
                }
            }

            Matrix rst;
            while (!que.empty())
                rst = rst.mul(que.front()), que.pop_front();
            rst.show();
        }
    }

    return 0;
}
