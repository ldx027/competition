#include <iostream>
#include <list>
#include <string>
using namespace std;

#define ll long long

ll n2ten(string num, int n)
{
    ll rst = 0;
    bool flg = true;
    for (auto it = num.begin(); it != num.end(); it++)
    {
        if (*it == '-')
        {
            flg = false;
            continue;;
        }
        rst *= n;
        if (*it >= '0' && *it <'9') rst += *it - '0';
        else if (*it >= 'A' && *it <= 'F') rst += *it - 'A' + 10;
    }

    return flg ? rst : -rst;
}

string ten2n(ll num, int n)
{
    bool flg = true;
    if (num < 0) flg = false, num *= -1;
    list<int> lst;
    while (num) 
    {
        lst.push_front(num % n); 
        num /= n;
    }

    string rst;
    if (!flg) rst.push_back('-');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        if (*it < 10) rst.push_back(*it + '0');
        else rst.push_back(*it + 'A' - 10);
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    string num;

    cin >> n >> num >> m;

    // cout << n2ten(num, n) << endl;
    cout << ten2n(n2ten(num, n), m) << endl;

    return 0;
}