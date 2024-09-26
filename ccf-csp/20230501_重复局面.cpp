#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string str, tmp;
    unordered_map<string, int> mp;

    while (n--)
    {
        str.clear(); 
        for (int i = 0; i < 8; i++)
        {
            cin >> tmp;
            str += tmp;
        }
        cout << ++mp[str] << endl;
    }

    return 0;
}