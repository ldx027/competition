#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<long long> &vec)
{
    long long rst = 0;
    for (long long i = 1; i < vec.size(); i++)
    {
        vec[i] += vec[i - 1];
        rst += vec[i];
    }
    return rst;
}

vector<long long> vec;
int main()
{
    long long N;
    while (true) 
    {
        cin >> N;
        if (N == 0) break;
        vec.resize(N);
        for (long long i = 0; i < N; i++) cin >> vec[i];
        sort(vec.begin(), vec.end());

        long long total = solve(vec);
        cout << total << endl;
    }

    return 0;
}