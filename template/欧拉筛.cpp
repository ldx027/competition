#include <iostream>
#include <vector>
using namespace std;

void euler(int beg, int end)
{
    if (end < 2) return;
    vector<bool> isPrime(end + 1, true);
    vector<int> primes;
    
    isPrime[1] = false;

    for (int i = 2; i <= end; i++)
    {
        if (isPrime[i]) primes.push_back(i);

        for (int j = 0; j < primes.size() && i * primes[j] <= end; j++)
        {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }

    for (auto it = primes.begin(); it != primes.end(); it++) if (*it >= beg) cout << *it << " ";
    cout << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;

    euler(a, b);

    return 0;
}