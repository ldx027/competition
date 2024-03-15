#include <iostream>
using namespace std;

void selectionSort(int* arr, int len);
void swap(int* arr, int a, int b);

int main()
{
    int arr[] = {5,2,8,4,6,9,1,7,3,0};
    int len = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void swap(int* arr, int a, int b)
{
    if (a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void selectionSort(int* arr, int len)
{
    for (int i = 0;i < len-1; i++)
    {
        int maxIdx = 0;
        for (int j = 0; j < len - i; j++)
        {
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        }
        swap(arr, len - 1 - i, maxIdx);
    }
}