#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, q;
    cin >> N >> q;

    vector<bool> isPrime(N + 1, true);
    vector<ll> primes;
    vector<int> input(q);
    int Max = 1;

    for (int i = 0; i < q; i++)
        cin >> input[i], Max = max(Max, input[i]);

    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i <= N; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
        
        if (primes.size() >= Max)
            break;

        for (ll j = 0; j < primes.size() && i * primes[j] <= N; j++)
        {
            isPrime[primes[j] * i] = false;
            if (i % primes[j] == 0)
                break;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << primes[input[i] - 1] << "\n";
    }

    return 0;
}