#include <iostream>
#include <cmath>
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

bool fun1(int a, int b, int c)
{
    return a + b <= c;
}

bool fun2(int a, int b, int c)
{
    return a * a + b * b == c * c;
}

bool fun3(int a, int b, int c)
{
    return a * a + b * b > c * c;
}

bool fun4(int a, int b, int c)
{
    return a * a + b * b < c * c;
}

bool fun5(int a, int b, int c)
{
    return a == b;
}

bool fun6(int a, int b, int c)
{
    return a == b && a == c;
}

int main()
{
    int arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];
    popSort(arr, 3);

    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << endl;

    if (fun1(arr[0], arr[1], arr[2]))
    {
        cout << "Not triangle" << endl;
        return 0;
    }

    if (fun2(arr[0], arr[1], arr[2]))
    {
        cout << "Right triangle" << endl;
    }
    if (fun3(arr[0], arr[1], arr[2]))
    {
        cout << "Acute triangle" << endl;
    }
    if (fun4(arr[0], arr[1], arr[2]))
    {
        cout << "Obtuse triangle" << endl;
    }
    if (fun5(arr[0], arr[1], arr[2]))
    {
        cout << "Isosceles triangle" << endl;
    }
    if (fun6(arr[0], arr[1], arr[2]))
    {
        cout << "Equilateral triangle" << endl;
    }

    return 0;
}
