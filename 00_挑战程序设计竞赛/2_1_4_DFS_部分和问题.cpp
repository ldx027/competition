#include <iostream>
using namespace std;

bool solve(int *arr,int len, int target, int i = 0, int sum = 0)
{
    if (i == len) return sum == target; 
    if (sum == target) return true;
    return solve(arr, len, target, i + 1, sum) || solve(arr, len, target, i + 1, sum + arr[i]);
}

int main()
{
    cout << solve()
}