#include <iostream>
#include <string>
using namespace std;

void change(string &str)
{
    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (*it >= 'A' && *it <= 'Z')
            *it += 'a' - 'A';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string find, input;
    getline(cin, find);
    getline(cin, input);
    change(find);
    change(input);

    find += ' ';
    input += ' ';

    int cnt = 0;
    int first = -1;

    for (int i = 0; i < input.size() - find.size();)
    {
        bool flg = true;
        for (int j = 0; j < find.size(); j++)
            if (find[j] != input[i + j])
            {
                flg = false;
                break;
            }
        if (flg)
        {
            cnt++;
            if (first == -1)
                first = i;
        }
        if (input[i] != ' ') while(input[i] != ' ') i++;
        while (input[i] == ' ') i++;
    }

    if (cnt)
        cout << cnt << " " << first << endl;
    else
        cout << -1 << endl;

    return 0;
}