#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

char dy(char c)
{
    switch(c)
    {
        case '(' : return ')';
        case '[' : return ']';
        case ')' : return '(';
        case ']' : return '[';
    }
}

int main()
{
    string str;
    list<char> exp;
    cin >> str;
    for (auto it = str.begin(); it != str.end(); it++) exp.push_back(*it);
    
    stack<pair<char, list<char>::iterator>> stk;

    auto it = exp.begin();
    for (; it != exp.end(); it++)
    {
        if (*it == '(' || *it == '[')
        {
            stk.push({*it, it});
        }
        else
        {
            if (!stk.empty() && stk.top().first == dy(*it))
            {
                stk.pop();
            }
            else
            {
                it = exp.insert(it, dy(*it));
                it++;
            }
        }
    }

    while (!stk.empty())
    {
        auto it = stk.top().second;
        it++;
        exp.insert(it, dy(stk.top().first));
        stk.pop();
    }

    for (auto it = exp.begin(); it != exp.end(); it++)
    {
        cout << *it;
    }

    return 0;
}