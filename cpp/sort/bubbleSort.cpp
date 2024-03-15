#include <iostream>
using namespace std;

void bubbleSort(int* arr, int len);

int main()
{
    int arr[] = {5, 7, 3, 9, 1, 4, 6, 8, 2, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void swap(int * arr, int a, int b)
{
    if (a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void bubbleSort(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j >= i; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}