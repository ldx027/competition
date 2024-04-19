#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> profix(string str)
{
    vector<int> pi(str.size(), 0);
    for (int i = 1; i < str.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) j = pi[j - 1];
        if (str[i] == str[j]) j++;
        pi[i] = j;
    }
    
    return pi;
}

void kmp(string str1, string str2)
{
    string str = str2 + "#" + str1;
    vector<int> pi = profix(str);
    for (int i = str2.size() + 1; i < pi.size(); i++)
    {
        if (pi[i] == str2.size())
        {
            cout << i - 2 * str2.size() + 1 << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    kmp(str1, str2);

    for (int i = 1; i <= str2.size(); i++)
    {
        string str = str2.substr(0, i);
        vector<int> pi = profix(str);
        cout << *pi.rbegin() << " ";
    }

    return 0;
}