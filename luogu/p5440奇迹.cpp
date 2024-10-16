#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> isPrime;
vector<int> primes;

void findPrime()
{
    isPrime.resize(1e9, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < 1e9; i++)
    {
        if (isPrime[i])
            primes.push_back(i);

        for (int j = 0; j < primes.size() && primes[j] * i < 1e9; j++)
        {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0)
                break;
            ;
        }
    }
}

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(string data)
{
    int y = 0, m = 0, d = 0;
    for (int i = 0; i < 4; i++)
        y = 10 * y + data[i] - '0';
    for (int i = 4; i < 6; i++)
        m = 10 * m + data[i] - '0';
    for (int i = 6; i < 8; i++)
        d = 10 * d + data[i] - '0';
    
    cout << y << " " << m << " " << d << endl;

    if (!y || !m || !d || m > 12)
        return false;

    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        month[2] = 29;
    else
        month[2] = 28;

    if (d > month[m])
        return false;

    if (!isPrime[100 * m + d] || !isPrime[1e4 * y + 1e2 * m + d])
        return false;

    return true;
}

int func(string str)
{
    int cnt = 0;

    vector<bool> miss(8, false);
    for (int i = 0; i < 8; i++)
        if (str[i] == '-')
            miss[i] = true, str[i] = '0';

    bool flg = true;
    while (flg)
    {
        flg = false;
        for (int i = 7; i >= 0; i--)
        {
            if (miss[i])
            {
                str[i]++;
                if (str[i] > '9')
                    str[i] = '0';
                else
                {
                    flg = true;
                    break;
                }
            }
        }
        cout << str << endl;
        cnt += check(str);
    }

    return cnt;
}

int main()
{
    findPrime();

    int T;
    cin >> T;

    string str;
    while (T--)
    {
        cin >> str;
        cout << func(str) << endl;
    }

    return 0;
}