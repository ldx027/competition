#include <iostream>
using namespace std;

void getNumber(char *buf, int *arr)
{
    int idx = 0;
    for (int i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] >= '0' && buf[i] <= '9') arr[idx++] = buf[i] - '0';
    }
}

int isbn(int *arr)
{
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        ans += arr[i] * (i + 1);
    }
    return ans % 11;
}

int main()
{
    char buf[14];
    int number[10];

    scanf("%s", buf);

    getNumber(buf, number);
    int ans = isbn(number);
    if (ans == number[9] || (ans == 10 && buf[12] == 'X'))
    {
        cout << "Right" << endl;
    }
    else
    {
        for (int i = 0; buf[i + 1] != '\0'; i++) cout << buf[i];
        if (ans != 10) cout << ans << endl;
        else cout << "X" << endl;
    }
    
    return 0;
}