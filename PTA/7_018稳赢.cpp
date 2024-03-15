#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;
    int n = k;
    string input; 
    while (cin >> input)
    {
        if (input == "End") break;
        if (k--)
        {
            if (input == "ChuiZi") cout << "Bu" << endl;
            else if (input == "JianDao") cout << "ChuiZi" << endl;
            else if (input == "Bu") cout << "JianDao" << endl;
        }
        else
        {
            cout << input << endl;
            k = n;
        }
    }

    return 0;
}