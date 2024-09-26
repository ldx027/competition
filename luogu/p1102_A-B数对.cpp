#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int main()
{
    ull N, C;
    cin >> N >> C;

    map<ull, ull> arr;

    ull x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        arr[x]++;
    }

    auto it1 = arr.begin(), it2 = arr.begin();
    it2++;

    ull cnt = 0;
    while (it2 != arr.end())
    {
        if (it2->first - it1->first > C)
            it1++;
        else if (it2->first - it1->first == C)
            cnt += it2->second * it1->second, it2++;
        else
            it2++;
    }

    cout << cnt << endl;

    return 0;
}