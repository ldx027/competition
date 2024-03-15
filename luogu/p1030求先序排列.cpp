#include <iostream>
#include <string>
using namespace std;

void dfs(string mid, string back)
{
    if (mid.size() == 0) return;
    int idx = mid.find(*back.rbegin());
    cout << mid[idx];

    dfs(mid.substr(0, idx), back.substr(0, idx));
    dfs(mid.substr(idx + 1), back.substr(idx, mid.size() - idx - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string mid, back;
    cin >> mid >> back;
    dfs(mid, back);

    return 0;
}