#include <iostream>
#include <vector>
using namespace std;

vector<int> vec(1001, 0);
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        vec[x]++;
    }

    int num = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (vec[i])
        {
            num++;
            ans.push_back(i);
        }
    }

    cout << num << endl;
    for (int i = 0; i < num; i++) cout << ans[i] << " ";

    return 0;
}