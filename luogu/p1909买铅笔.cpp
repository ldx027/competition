#include <iostream>
using namespace std;

int cell(double x)
{
    return (x == int(x) ? x : x + 1);
}

int main()
{
    int n;
    int arr[3][2];
    int ans[3];
    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i / 2][i % 2];
    }
    for (int i = 0; i < 3; i++)
    {
        ans[i] = cell(double(n) / arr[i][0]) * arr[i][1];
    }
    int min = ans[0];
    for (int i = 0; i < 3; i++)
    {
        if (ans[i] < min) min = ans[i];
    }
    cout << min << endl;
    return 0;
}