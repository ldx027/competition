#include <iostream>
#include <vector>
using namespace std;

struct Xs { int a, b, c; };
inline double func(Xs xs, double x) { return xs.a * x * x + xs.b * x + xs.c; }

int main()
{
    int T;
    cin >> T;

    vector<Xs> vec;
    while (T--)
    {
        int n;
        cin >> n;

        vec.resize(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i].a >> vec[i].b >> vec[i].c;
        
        double l = 0, r = 1e3;
    }
}