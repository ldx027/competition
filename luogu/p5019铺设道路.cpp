#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int ans = 0;

    for (int i = 0; i < n;)
    {
        if (vec[i] > 0)
        {
            for (int j = i; j < n && vec[j] > 0; j++)
            {
                vec[j]--;
            }
            ans++;
        }
        else i++;
    }
    
    cout << ans << endl;

    return 0;
}