#include <iostream>
#include <string>
#include <stack>
using namespace std;

int readNum(string str, int *beg)
{
    int rst = 0;
    while (str[*beg] != '.')
    {
        rst *= 10;
        rst += str[*beg] - '0';
        *beg += 1;
    }
    // cout << "read:" << rst << endl;
    return rst;
}

int main()
{
    string exp;
    stack<int> numbers;
    int num1, num2;

    cin >> exp;

    for (int i = 0; exp[i] != '@'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            numbers.push(readNum(exp, &i));
        }
        else 
        {
            num2 = numbers.top();
            numbers.pop();
            num1 = numbers.top();
            numbers.pop();

            if (exp[i] == '+')
                numbers.push(num1 + num2);
            else if (exp[i] == '-')
                numbers.push(num1 - num2);
            else if (exp[i] == '*')
                numbers.push(num1 * num2);
            else if (exp[i] == '/')
                numbers.push(num1 / num2);
            // cout << "rst" << numbers.top() << endl;
        }
    }
    cout << numbers.top();

    return 0;
}