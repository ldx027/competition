#include <iostream>
#include <ctime>
#include <random>
using namespace std;

void quickSort(int* arr, int L, int R);
int* partition(int* arr, int L, int R);

void swap(int* arr, int a, int b)
{
    if (a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void printArr(int* arr, int len)
{
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << endl;
}

void quickSort(int* arr, int len)
{
    quickSort(arr, 0, len - 1);
}

void quickSort(int* arr, int L, int R)
{
    if (L >= R) return;

    srand(time(nullptr));
    swap(arr, rand() % (R - L + 1) + L, R);
    int* res = partition(arr, L, R);
    quickSort(arr, L, res[0]);
    quickSort(arr, res[1], R);
    delete[] res;
}

int* partition(int* arr, int L, int R)
{
    int left = L - 1;
    int right = R;
    while (L < right)
    {
        if (arr[L] < arr[R]) swap(arr, ++left, L++);
        else if (arr[L] == arr[R]) ++L;
        else if (arr[L] > arr[R]) swap(arr, --right, L);
    }
    swap(arr, right++, R);
    return new int[2] {left, right};
}

int main()
{
    int arr[] = {5, 2, 8, 4, 6, 7, 9, 1, 3, 0};
    int len = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, len);
    printArr(arr, len);

    return 0;
}