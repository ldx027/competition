#include <iostream>
using namespace std;

void sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];
    sort(arr, 3);
    int yue = gcd(arr[2], arr[0]);

    printf("%d/%d", arr[0]/yue, arr[2]/yue);

    return 0;
}