#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix(string str)
{
    int n = str.size();
    vector<int> rst(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = rst[i - 1];
        while (j > 0 && str[i] == str[j]) j = rst[j - 1];
        if (str[i] == str[j]) j++;
        rst[i] = j;
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}