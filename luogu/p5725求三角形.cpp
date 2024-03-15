#include <iostream>
#include <string>
using namespace std;

void func1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%02d", n * i + j + 1);
        }
        printf("\n");
    }
}

void func2(int n)
{
    int now = 1;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (; j < n - 1 - i; j++) printf("  ");
        for (; j < n; j++) printf("%02d", now++);
        printf("\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    func1(n);
    printf("\n");
    func2(n);

    return 0;
}