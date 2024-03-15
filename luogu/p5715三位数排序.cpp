#include <iostream>
using namespace std;

void popSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
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

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int arr[3] = {a, b, c};
    popSort(arr, 3);
    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}