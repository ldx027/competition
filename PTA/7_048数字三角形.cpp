#include <iostream>
using namespace std;

void show(int x, char c)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - 1- i; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << c;
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        show(a, b);
    }

    return 0;
}