#include <iostream>
#include <vector>
using namespace std;

vector<bool> isP;
vector<int> prime;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    int cur = 0;
    cin >> n >> q;
    isP.resize(n + 1, 1);
    isP[0] = isP[1] = 0;
    prime.resize(q);

    for (int i = 2; i <= n; i++)
    {
        
    }
}
