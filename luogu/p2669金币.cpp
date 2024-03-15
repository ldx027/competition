#include <iostream>
using namespace std;

int solve(int k)
{
    int days = 1;
    int coin = 0;
    for (int i = 1;;i++)
    {
        for (int j = i; j > 0; j--)
        {
            coin += i;
            if (days++ == k) return coin;
        }
    }    
}

int main()
{
    int k;
    cin >> k;

    cout << solve(k) << endl;

    return 0;
}