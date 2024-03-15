#include <iostream>
#include <vector>
using namespace std;

int win[5][5] =
    {
        {0, 1, 2, 2, 1},
        {2, 0, 1, 2, 1},
        {1, 2, 0, 1, 2},
        {1, 1, 2, 0, 2},
        {2, 2, 1, 1, 0},
    };

vector<int> a;
vector<int> b;

int main()
{
    int N, ta, tb;
    cin >> N >> ta >> tb;
    a.resize(ta);
    b.resize(tb);
    int scorea = 0, scoreb = 0;

    for (int i = 0; i < ta; i++) cin >> a[i];
    for (int i = 0; i < tb; i++) cin >> b[i];

    for (int i = 0; i < N; i++)
    {
        int winer = win[a[i % ta]][b[i % tb]];
        if (winer == 1)
            scoreb++;
        else if (winer == 2)
            scorea++;
    }

    cout << scorea << " " << scoreb << endl;

    return 0;
}