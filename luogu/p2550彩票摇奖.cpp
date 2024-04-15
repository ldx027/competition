#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, x;
    cin >> n;

    vector<bool> ans(34, false);
    vector<int> vec(8, 0);

    for (int i = 0; i < 7; i++)
    {
        cin >> x;
        ans[x] = true;
    }

    while (n--)
    {
        int cnt = 0;
        for (int i =  0; i < 7; i++)
        {
            cin >> x;
            if (ans[x]) cnt++;
        }

        vec[cnt]++;
    }

    for (int i = 7; i > 0; i--)
    {
        cout << vec[i] << " ";
    }

    return 0;
}