#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    string str;
    for (int i = 0; i < 3 * k; i++)
    {
        cin >> str;
        int abc[3] = {0, 0, 0};
        int need = 0;
        for (int j = 0; j < 3; j++)
        {
            if (str[j] >= 'A' && str[j] <= 'C') abc[str[j] - 'A'] = 1;
            if (str[j] == '?')
            {
                need = 1;
            }
        }
        if (need)
        {
            int j;
            for (j = 0; abc[j] != 0 && j < 3; j++);
            cout << char('A' + j) << endl;
        }
    }

    return 0;
}