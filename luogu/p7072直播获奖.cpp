#include <iostream>
#include <vector>
using namespace std;

int ward(int p, int w)
{
    return max(1, p * w / 100);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<int> vec(601, 0);

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec[x]++;
        int num = ward(i + 1, w);
        int idx = 600;
        while (num > vec[idx] || !vec[idx])
        {
            num -= vec[idx--];
        }
        cout << idx << " ";
    }

    return 0;
}