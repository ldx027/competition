#include <iostream>
using namespace std;

void insertSort(int* arr, int len);
void swap(int* arr, int a, int b);
void printArr(int* arr, int len);

int main()
{
    int  arr[] = {5, 8, 2, 7, 3, 9, 1, 4, 6, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr, len);
    printArr(arr, len);
    return 0;
}

void insertSort(int* arr, int len)
{
    for (int i = 1;i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr, j, j - 1);
            else
                break;
        }
    }
}

void swap(int* arr, int a, int b)
{
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void printArr(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}