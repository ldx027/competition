#include <iostream>
#include <vector>
using namespace std;

vector<bool> isPrimer;
vector<int> primers;

void func(int n)
{
    isPrimer.resize(n + 1, true);
    primers.clear();

    for (int i = 2; i <= n; i++)
    {
        if (isPrimer[i]) primers.push_back(i);
        for (int j = 0; primers[j] * i <= n; j++)
        {
            isPrimer[i * primers[j]] = false;
            if (i % primers[j] == 0) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;
    func(b);
    for (auto it = primers.begin(); it != primers.end(); it++)
    {
        if (*it >= a) cout << *it << " ";
    }

    return 0;
}