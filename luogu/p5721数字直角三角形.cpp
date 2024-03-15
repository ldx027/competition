#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 1;

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%02d", num++);
        }
        printf("\n");
    }

    return 0;
}