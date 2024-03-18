#include <iostream>
#include <list>
#include <string>
using namespace std;

#define ll long long

ll n2ten(string num, int n)
{
    ll rst = 0;

    for (auto it = num.begin(); it != num.end(); it++)
    {
        rst *= n;
        if (*it >= '0' && *it <= '9') rst += *it - '0';
        else if (*it >= 'A' && *it <= 'F') rst += *it - 'A' + 10;
    }

    return rst;
}

string ten2n(ll num, int n)
{
    list<int> lst;
    while (num) 
    {
        lst.push_front(num % n); 
        num /= n;
    }

    string rst;
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
    string str = ten2n(n2ten(num, n), m);
    if (str.size() == 0) str = "0";
    cout << str << endl;

    return 0;
}