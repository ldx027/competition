#include <iostream>
#include <string>
using namespace std;

void read(string input, int &a, int &b, char &sign)
{
    int idx = 0;
    if (input[0] >= 'a' && input[0] <= 'c')
    {
        sign = input[0];
        while (!(input[idx] >= '0' && input[idx] <= '9')) ++idx;
    }

    a = b = 0;
    while (input[idx] >= '0' && input[idx] <= '9') a = a * 10 + input[idx++] - '0';
    while (!(input[idx] >= '0' && input[idx] <= '9')) ++idx;
    while (input[idx] >= '0' && input[idx] <= '9') b = b * 10 + input[idx++] - '0';
}

char fh(char sign)
{
    if (sign == 'a') return '+';
    if (sign == 'b') return '-';
    if (sign == 'c') return '*';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string input;
    getline(cin, input);

    int a, b;
    char sign = 'a';

    for (int i = 0; i < N; i++)
    {
        getline(cin, input);
        read(input, a, b, sign);
        int ans;
        if (sign == 'a') ans = a + b;
        else if (sign == 'b') ans = a - b;
        else if (sign == 'c') ans = a * b;
        string output = std::to_string(a) + fh(sign) + std::to_string(b) + "=" + std::to_string(ans);
        cout << output << endl;
        cout << output.size() << endl;
    }

    return 0;
}