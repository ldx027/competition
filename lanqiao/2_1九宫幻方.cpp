#include <iostream>
using namespace std;

void print(int *arr)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i * 3 + j];
        }
        cout << endl;
    }
}

bool isHuanFang(int *arr)
{
    int mol[3] = { 0 }, row[3] = { 0 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mol[i] += arr[i * 3 + j];
            row[j] += arr[i * 3 + j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (mol[i] != 15 || row[i] != 15) return false;
    }
    if (arr[0] + arr[4] + arr[8] != 15) return false;
    if (arr[2] + arr[4] + arr[6] != 15) return false;

    return true;
}

bool have(int *arr, int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == x) return true;
    }

    return false;
}

void dfs(int *arr, int idx, int *rst, int *n)
{
    if (arr[idx] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!have(arr, i))
            {
                arr[idx] = i;
                dfs(arr, idx, rst, n);
                arr[idx] = 0;
            }
        }
    }
    else if (idx < 8)
    {
        dfs(arr, idx + 1, rst, n);
    }
    else
    {
        if (isHuanFang(arr))
        {
            for (int i = 0; i < 9; i++) rst[i] = arr[i];
            *n += 1;
        }
    }
}

int main()
{
    int arr[9];
    for (int i = 0; i < 9; i++) cin >> arr[i];
    int rst[9], n = 0;
    dfs(arr, 0, rst, &n);
    if (n == 1)
    {
        print(rst);
    }
    else
    {
        cout << "too more" << endl;
    }

    return 0;
}