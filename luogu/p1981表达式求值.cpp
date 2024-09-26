#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define ll long long

int main()
{
    string exp;
    cin >> exp;

    string suf;

    stack<ll> num;
    stack<char> op;

    ll tmp = 0;
    for (auto it = exp.begin(); it != exp.end(); it++)
    {
        if (*it >= 0 && *it <= 9)
        {
            tmp *= 10;
            tmp += *it - '0';
        }

        else
        {
            num.push(tmp);
            tmp = 0;
        }
    }
}