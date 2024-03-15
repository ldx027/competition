#include <iostream>
using namespace std;

void mergeSort(int* arr, int len);
void mergeSort(int* arr, int L, int R);
void merge(int* arr, int L, int M, int R);

void printArr(int* arr, int len);
void swap(int* arr, int a, int b);

int main()
{
    int arr[] = {5,2,8,3,7,1,9,6,4,0};
    int len = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, len);
    printArr(arr, len);
    return 0;
}

void printArr(int* arr, int len)
{
    for (int i = 0;i < len;i ++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int* arr, int a, int b)
{
    if (a==b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void mergeSort(int* arr, int len)
{
    mergeSort(arr, 0, len - 1);
}

void mergeSort(int* arr, int L, int R)
{
    if (R - L <= 0) return;
    
    int M = L + ((R - L) >> 1);
    mergeSort(arr, L, M);
    mergeSort(arr, M + 1, R);
    merge(arr, L, M, R);
}

void merge(int* arr, int L, int M, int R)
{
    int* help = new int[R - L + 1];
    int p1 = L, p2 = M + 1;
    int now = 0;

    while(now < R - L + 1)
    {
        if (p1 <= M && p2 <= R)
            help[now++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        else if(p1 <= M)
            help[now++] = arr[p1++];
        else if (p2 <= R)
            help[now++] = arr[p2++];
    }

    for (int i = 0; i < R - L + 1; i++)
        arr[L + i] = help[i];

    delete[] help;
}