#include <iostream>
#include <vector>
using namespace std;

void eular(int beg, int end)
{
    vector<bool> isPrime(end + 1, true); 
    vector<int> primes;

    for (int i = 2; i <= end; i++)
    {
        if (isPrime[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= end; j++)
        {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] > end) break;
        if (primes[i] >= beg) cout << primes[i] << " ";
    }
    cout << endl;
}

int main()
{
    eular(2, 100);

    return 0;
}