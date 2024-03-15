#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<bool> vec;
    vector<int> prime;
    vector<int> begin;
    vector<int> end;
    int cur = 0;
    int a, b;
    while (cin >> a >> b)
    {
        begin.push_back(a);
        end.push_back(b);
    }
    vec.resize(*max_element(end.begin(), end.end()), true);
    prime.resize(vec.size(), 0);
    vec[0] = vec[1] = false;

    for (int i = 2; i <= vec.size(); i++)
    {
        if (vec[i])
            prime[cur++] = i;
        for (int j = 0; j < cur && i * prime[j] <= vec.size(); j++)
        {
            vec[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }

    for (int i = 0; i < begin.size(); i++)
    {
        bool have = 0;
        int j;
        for (j = 0; prime[j] < begin[i]; j++);
        for (; prime[j] <= end[i] && j < cur; j++)
        {
            if (have) cout << " ";
            have = 1;
            cout << prime[j];
        }
        cout << endl;
    }

    return 0;
}