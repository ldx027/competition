#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int deal(vector<int> &vec)
{
    int rst = 0;
    for (int i = vec.size() - 2; i >= 0; i--)
    {
        rst += vec[i] + vec[i + 1] - 1;
        vec[i] += vec[i + 1];
    }

    return rst;
}

vector<int> worst;
vector<int> best;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;
    worst.resize(k);
    for (int i = 0; i < k; i++) cin >> worst[i];
    best = worst;
    reverse(best.begin(), best.end());

    cout << deal(worst) << " " << deal(best) << endl;

    return 0;
}