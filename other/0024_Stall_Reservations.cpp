#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> beg;
vector<int> ed;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N + 1, 0);
    beg.resize(N + 1, 0);
    ed.resize(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> beg[i] >> ed[i];
    }

    int max = 1;

}