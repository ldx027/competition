#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    vector<int> vec;
    while (cin >> x)
        vec.push_back(x);
    
    vector<int> dp(vec.size(), 1);
    for (int i = 1; i < dp.size(); i++)
        for (int j = 0; j < i; j++)
            if (vec[j] >= vec[i])
                dp[i] = max(dp[i], dp[j] + 1);
    
    cout << *max_element(dp.begin(), dp.end()) << endl;

    vector<int> sys;
    for (int i = 0; i < vec.size(); i++)
    {
        bool flg = false;
        for (int j = 0; j < sys.size(); j++)
        {
            if (sys[j] >= vec[i])
            {
                sys[j] = vec[i];
                flg = true;
                break;
            }
        }
        if (!flg)
            sys.push_back(vec[i]);
    }

    cout << sys.size() << endl;

    return 0;
}