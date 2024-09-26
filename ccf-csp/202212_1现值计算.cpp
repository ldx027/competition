#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    double p;


    cin >> n >> p;
    n++;

    vector<int> vec(n);
    
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    double total = 0;

    double cur = 1;
    for (int i = 0; i < n; i++)
    {
        total += vec[i] * cur;
        cur /= (1 + p);
    }

    cout << total << endl;

    return 0;
}