#include <iostream>
using namespace std;

void popSort(int *arr, int len)
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

int main()
{
    int arr[3];
    char buf[4]; 
    for (int i = 0; i < 3; i++) cin >> arr[i];
    scanf("%s", buf);
    popSort(arr, 3);
    for (int i = 0; i < 3; i++) cout << arr[buf[i] - 'A'] << " ";
    cout << endl;

    return 0;
}