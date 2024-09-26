#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f

int main()
{
    int n;
    cin >> n;

    vector<int> *old = new vector<int>(n + 1, inf), *cur = new vector<int>(n + 1, inf);

    for (int i = 1; i <= n; i++)
        old->at(i) = i - 1;
    

    for (int i = 2; i < n; i++)
    {
        cur->at(i) = inf;
        for (int j = i + 1; j <= n; j++)
        {
            cur->at(j) = (old->at(j - i) == inf ? inf : old->at(j - i) + 1);
            cout << cur->at(j) << " ";
        }
        cout << endl;

        vector<int> *tmp = old;
        old = cur;
        cur = tmp;
    }


    cout << cur->at(n);
}