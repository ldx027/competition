#include <iostream>
#include <vector>
using namespace std;

#define ll long long 

typedef vector<vector<ll>> Matrix;

void T(Matrix &mat)
{
    Matrix rst(mat[0].size(), vector<ll>(mat.size()));

    for (ll i = 0; i < mat.size(); i++)
        for (ll j = 0; j < mat[0].size(); j++)
            rst[j][i] = mat[i][j];
    mat = rst;
}

void mul(Matrix &mat1, const Matrix &mat2)
{
    ll h = mat1.size();
    ll m = mat2.size();
    ll w = mat2[0].size();

    Matrix rst(h, vector<ll>(w, 0));

    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            for (ll u = 0; u < m; u++)
            {
                rst[i][j] += mat1[i][u] * mat2[u][j];
            }
        }
    }

    mat1 = rst;
}

void dot(const vector<ll> &vec, Matrix &mat)
{
    for (ll i = 0; i < vec.size(); i++)
    {
        for (ll j = 0; j < mat[0].size(); j++)
        {
            mat[i][j] *= vec[i];
        }
    }
}

void read(ll h, ll w, Matrix &mat)
{
    mat.clear();
    mat.resize(h, vector<ll>(w));
    for (ll i = 0; i < h; i++)
        for (ll j = 0; j < w; j++)
            cin >> mat[i][j];
}

void show(const Matrix &mat)
{
    for (ll i = 0; i < mat.size(); i++)
    {
        for (ll j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, d;
    cin >> n >> d;

    Matrix Q, K, V;
    vector<ll> W(n);

    read(n, d, Q);
    read(n, d, K);
    read(n, d, V);

    for (int i = 0; i < n; i++)
        cin >> W[i];

    T(K);
    mul(K, V);
    mul(Q, K);
    dot(W, Q);

    show(Q);
    
    return 0;
}