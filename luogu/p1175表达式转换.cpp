#include <iostream>
#include <vector>
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

int priority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
    case '%':
        return 3;
    default:
        return 0;
    }
}

vector<string> change2suffix(string exp)
{
    vector<string> out;

    for (auto it = exp.begin(); it != exp.end(); it++)
        while (*it == ' ')
            it = exp.erase(it) - 1;

    stack<char> stk;

    for (int i = 0; i < exp.size(); i++)
    {
        string num;
        if (exp[i] == '-' && i != exp.size() - 1 && exp[i + 1] >= '0' && exp[i + 1] <= '9' || exp[i] >= '0' && exp[i] <= '9')
        {
            if (exp[i] == '-')
                num += '-', i++;
            while (exp[i] >= '0' && exp[i] <= '9')
                num += exp[i++];
            out.push_back(num);
            i--;
        }
        else
        {
            if (exp[i] == ')')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    string tmp;
                    tmp += stk.top();
                    out.push_back(tmp);
                    stk.pop();
                }
                stk.pop();
            }
            else if (exp[i] == ']')
            {
                while (!stk.empty() && stk.top() != '[')
                {
                    string tmp;
                    tmp += stk.top();
                    out.push_back(tmp);
                    stk.pop();
                }
                stk.pop();
            }
            else if (exp[i] == '}')
            {
                while (!stk.empty() && stk.top() != '{')
                {
                    string tmp;
                    tmp += stk.top();
                    out.push_back(tmp);
                    stk.pop();
                }
                stk.pop();
            }
            else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            {
                stk.push(exp[i]);
            }
            else
            {
                while (!stk.empty() && (priority(exp[i]) < priority(stk.top()) || priority(exp[i]) != 3 && priority(exp[i]) == priority(stk.top())))
                {
                    if (stk.top() != '(' && stk.top() != '[' && stk.top() != '{')
                    {
                        string tmp;
                        tmp += stk.top();
                        out.push_back(tmp);
                    }
                    stk.pop();
                }
                stk.push(exp[i]);
            }
        }
    }

    while (!stk.empty())
    {
        string tmp;
        tmp += stk.top();
        out.push_back(tmp);
        stk.pop();
    }
    return out;
}

bool step()
{return false;}

int main()
{
    string exp;
    vector<string> out;

    getline(cin, exp);

    out = change2suffix(exp);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
    cout << endl;

    return 0;
}