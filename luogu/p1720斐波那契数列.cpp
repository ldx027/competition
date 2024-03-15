#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> vec(3);
    vec[1] = 1;
    vec[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        vec.push_back(vec[i - 1] + vec[i - 2]);
    }

    cout << vec[n] << ".00" << endl;

    return 0;
}