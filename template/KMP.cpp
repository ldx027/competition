#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getNext(string str)
{
    int n = str.size();
    vector<int> next(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int j = next[i];
        while (j && str[i] != str[j])
            j = next[j];
        if (str[i] == str[j])
            next[i + 1] = j + 1;
    }

    return next;
}

void kmp(string s, string p)
{
    vector<int> next = getNext(p);
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j && s[i] != p[j])
            j = next[j];
        if (s[i] == p[j])
            j++;
        if (j == p.size())
            cout << i + 1 - j << endl;
    }
}

int main()
{
    string s, p;
    cin >> s >> p;
    kmp(s, p);

    return 0;
}