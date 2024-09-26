#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N = 100;

    vector<bool> isPrime(N + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
            primes.push_back(i);

        for (int j = 0; j < primes.size() && i * primes[j] <= N; j++)
        {
            isPrime[primes[j] * i] = false;
            if (i % primes[j] == 0)
                break;
        }
    }

    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";

    return 0;
}