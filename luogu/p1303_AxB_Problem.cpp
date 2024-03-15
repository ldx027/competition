#include <iostream>
#include <string>
#include <vector>
using namespace std;

void change(string str, vector<int> *vec);
void digit(vector<int> *rst);
void mul(vector<int> a1, vector<int> a2, vector<int> *rst);
void showNum(vector<int> vec);

int main()
{
    string str1;
    string str2;
    vector<int> a1, a2;
    cin >> str1 >> str2;
    change(str1, &a1);
    change(str2, &a2);
    vector<int> rst;
    mul(a1, a2, &rst);
    showNum(rst);

    return 0;
}

void showNum(vector<int> vec)
{
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *it << "";
    }
    cout << endl;
}

void mul(vector<int> a1, vector<int> a2, vector<int> *rst)
{
    rst->clear();
    rst->resize((a1.size() + a2.size() + 3), 0);
    // showNum(*rst);
    for (int i = 0; i < a1.size(); i++)
    {
        for (int j = 0; j < a2.size(); j++)
        {
            // cout << "mul" << i << " " << j << "put" << i * j << " ans" << a1[i] * a2[j] << endl; 
            (*rst)[i + j] += a1[i] * a2[j];
        }
    }
    digit(rst);
    while (rst->back() == 0 && rst->size() > 1)
    {
        rst->pop_back();
    }
}

void change(string str, vector<int> *vec)
{
    for (auto it = str.rbegin(); it != str.rend(); it++)
    {
        vec->push_back(*it - '0');
    }
}

void digit(vector<int> *rst)
{
    for (int i = 0; i < rst->size(); i++)
    {
        if ((*rst)[i] > 9)
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