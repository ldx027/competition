#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int minIdx = 0;
    for (int i = 1; i < n; i++) if (arr[i] < arr[minIdx]) minIdx = i;
    
    cout << arr[minIdx] << endl;

    return 0;
}