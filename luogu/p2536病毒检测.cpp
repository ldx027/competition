#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cnt = 1;
vector<vector<int>> trie;
vec

int val(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'T':
        return 2;
    case 'G':
        return 3;
    }
}

void build(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '*')
        {

        }
        else if (str[i] == '?')
        {

        }
        else
        {
            int k = val(str[i]);

        }
    }
}


int main()
{
    string frag;
    cin >> frag;

}