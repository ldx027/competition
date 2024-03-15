#include <iostream>
#include <random>
#include <ctime>
using namespace std;

template <typename T>
void swap(T* arr, int a, int b)
{
    if (a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

template <typename T>
void printArr(T* arr, int len)
{
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
class Sorter
{
public:
    void sort(T* arr, int len){}
};

template <typename T>
class PopSorter : public Sorter<T>
{
public:
    void sort(T* arr, int len)
    {
        for (int i = 0; i < len - 1; i++)
            for (int j = 0; j < len - 1 - i; j++)
                if (arr[j] > arr[j + 1]) swap(arr, j, j + 1);
    }
};

template <typename T>
class InsertSorter : public Sorter<T>
{
public:
    void sort(T* arr, int len)
    {
        for (int i = 0; i < len - 1; i++)
            for (int j = 0; j < i + 1;j++)
            {
                if (arr[j] > arr[j + 1]) swap(arr, j, j + 1);
                else break;
            }
    }
};

template <typename T>
class MergeSorter : public Sorter<T>
{
public:
    void sort(T* arr, int len)
    {
        mergeSort(arr, 0, len - 1);
    }

private:
    void mergeSort(T* arr, int L, int R)
    {
        if (R == L) return;
        int M = L + ((R - L) >> 1);
        mergeSort(arr, L, M);
        mergeSort(arr, M + 1, R);
        merge(arr, L, M, R);
    }

    void merge(T* arr, int L, int M, int R)
    {
        T* help = new T[R - L + 1];
        int idx = 0;
        int p1 = L, p2 = M + 1;

        while (p1 <= M && p2 <= R)
            help[idx++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
        while (p1 <= M)
            help[idx++] = arr[p1++];
        while (p2 <= R)
            help[idx++] = arr[p2++];
        
        for (int i = 0; i < R - L + 1; i++)
            arr[L + i] = help[i];
        
        delete[] help;
    }
};

template <typename T>
class QuickSort : public Sorter<T>
{
public:
    void sort(T* arr, int len)
    {
        quickSort(arr, 0, len - 1);
    }

private:
    void quickSort(T* arr, int L, int R)
    {
        if (L >= R) return;

        srand(time(nullptr));
        swap(arr, R , rand() % (R - L + 1) + L);
        int *res = partition(arr, L, R);
        quickSort(arr, L, res[0] - 1);
        quickSort(arr, res[1] + 1, R);
        delete[] res;
    }
    
    int* partition(int* arr, int L, int R)
    {
        int left = L - 1, right = R;
       
        while (L < right)
        {
            if (arr[L] < arr[R])
                swap(arr, ++left, L++);
            else if (arr[L] > arr[R])
                swap(arr, --right, L);
            else
                L++;
        }
        swap(arr, R, right);
        return new int[2] {left + 1, right};
    }
};

template <typename T>
class HeapSorter : public  Sorter<T>
{
public:
    void sort(T *arr, int len)
    {
        heapSize = 0;
        for (int i = 0; i < len; i++)
        {
            heapInsert(arr);
        }
    }

private:
    void heapInsert(T *arr)
    {
        int idx = heapSize++;
        while (1)
        {
            if (arr[idx] > arr[(idx - 1) / 2])
            {
                swap(arr, idx, (idx - 1) / 2);
                idx = (idx - 1) / 2;
            }
            else break;
        }
        printArr(arr, 10);
    }

    void heapIfy(T *arr)
    {
        swap(arr, --heapSize, 0);
        int idx = 0;
    }



private:
    int heapSize;
};

int main()
{
    int arr[] = {5, 8, 2, 4, 6, 1, 3, 9, 7, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    HeapSorter<int> sorter;
    sorter.sort(arr, len);
    printArr(arr, len);

    return 0;
}