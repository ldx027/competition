#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int n, q, k;
    cin >> n >> q;
    vector<int> vec;
    vector<int> p;
    for (int i = 0; i <= n; i++)
    {
        vec.push_back(i);
    }
    for (int i = 2; i <= n; i++)
    {
        if (vec[i] == i)
        {
            p.push_back(i);
            for (int j = 2; i * j <= n; j++)
            {
                vec[i * j] = 0;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> k;
        cout << p[k - 1] << endl;
    }

    return 0;
}
