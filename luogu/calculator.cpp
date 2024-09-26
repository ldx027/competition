#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define ll long long

ll read(const string &exp, int &idx)
{
    bool flg = false;
    if (exp[idx] == '-')
        idx++, flg = true;
    ll rst = 0;

    while (idx < exp.size() && exp[idx] >= '0' && exp[idx] <= '9')
    {
        rst *= 10;
        rst += exp[idx++] - '0';
    }

    return flg ? -rst : rst;
}

int main()
{
    string exp;
    string out;

    getline(cin, exp);

    for (auto it = exp.begin(); it != exp.end(); it++)
        while (*it == ' ')
            it = exp.erase(it);
    
    cout << "exp:" << exp << endl;

    stack<char> stk;

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '-')
            out += '-', i++;
        while (exp[i] >= '0' && exp[i] <= '9')
            out += exp[i++];

        if (i >= exp.size())
            break;
        

    }
}