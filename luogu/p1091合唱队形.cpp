#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #define debug

int n;
vector<int> vec;

template <typename T>
void show(vector<T> vec)
{
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n;
    
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<int> dp1(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (vec[j] < vec[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);

    vector<int> dp2(n, 1);
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            if (vec[j] < vec[i])
                dp2[i] = max(dp2[i], dp2[j] + 1);

    vector<int> dp3(n);
    for (int i = 0; i < n; i++)
        dp3[i] = dp1[i] + dp2[i];

#ifdef debug    
    cout << "dp1" << endl;
    show(dp1);
    cout << "dp2" << endl;
    show(dp2);
    cout << "dp3" << endl;
    show(dp3);
#endif

    cout << n + 1 - *max_element(dp3.begin(), dp3.end()) << endl;
    return 0;
}