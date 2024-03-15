#include <iostream>
#include <string>
using namespace std;

bool isV(char c)
{
    return (c == 'a' || c == 'e');
}

int main()
{
    int t;
    cin >> t;
    int n;
    string in;
    string out;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> in;
        auto it = in.rbegin();
        while (it != in.rend())
        {
            int len = isV(*it) ? 2 : 3;
            for (int j = 0; j < len; j++)
            {
                out.push_back(*it);
                it++;
            }
            out.push_back('.');
        }
        auto it2 = out.rbegin();
        it2++;
        while (it2 != out.rend())
        {
            cout << *it2;
            it2++;
        }
        cout << endl;
        out.clear();
    }

    return 0;
}