#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> isPrime;
vector<int> primes;

void findPrime()
{
    isPrime.resize(10000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 10000; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
        
        for (int j = 0; j < primes.size() && i * primes[j] < 10000; j++)
        {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0)
                break;
        }
    }
}

bool check(string data)
{
    int y = 0, m = 0, d = 0;

    for (int i = 0; i < 4; i++)
        y = 10 * y + data[i] - '0';
    for (int i = 4; i < 6; i++)
        m = 10 * m + data[i] - '0';
    for (int i = 6; i < 8; i++)
        d = 10 * d + data[i] - '0';

    /*
        TODO 
        检测日期是否合法
    */

    return isPrime[y] && isPrime[m] && isPrime[d];
}

int func(string data)
{
    vector<int> miss;

    for (int i = 0; i < 8; i++)
        if (data[i] == '-')
            miss.push_back(i);
    
    string cur = data;
    int cnt = 0;

    /*
        TODO 
        深搜为cur赋值
    */
    
    return cnt;
}

int main()
{
    findPrime();

    int T;
    cin >> T;

    string data;
    while (T--)
    {
        cin >> data;
        cout << func(data) << endl;
    }

    return 0;
}