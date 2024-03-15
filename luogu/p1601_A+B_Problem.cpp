#include <iostream>
#include <string>
#include <vector>
using namespace std;

void change(string num, vector<int> *a)
{
    for (auto it = num.rbegin(); it != num.rend(); it++)
    {
        a->push_back(*it - '0');
    }
}

void show(vector<int> vec)
{
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *it << "";
    }
    cout << endl;
}

void digit(vector<int> *);
void sum(vector<int> a1, vector<int> a2, vector<int> *ans)
{
    ans->clear();
    for (int i = 0; i < max(a1.size(), a2.size()); i++)
    {
        int digit = 0;
        if (i < a1.size())
            digit += a1[i];
        if (i < a2.size())
            digit += a2[i];
        ans->push_back(digit);
    }
    digit(ans);
}

void digit(vector<int> *rst)
{
    for (int i = 0; i < rst->size(); i++)
    {
        if (rst->at(i) > 9)
        {
            if (i < rst->size() - 1)
            {
                (*rst)[i + 1] += (*rst)[i] / 10;
            }
            else
            {
                rst->push_back((*rst)[i] / 10);
            }
            (*rst)[i] %= 10;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    string number1, number2;
    vector<int> a1, a2;
    cin >> number1 >> number2;

    change(number1, &a1);
    change(number2, &a2);

    vector<int> ans;
    sum(a1, a2, &ans);
    show(ans);

    return 0;
}