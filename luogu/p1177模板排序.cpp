#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> vec;

void show(vector<long long> vec)
{
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}

void func1()
{
    sort(vec.begin(), vec.end());
}

void swap(vector<long long> &vec, int a, int b)
{
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

void dfs(vector<long long> &vec, int beg, int end)
{
    if (beg >= end) return;

    int num = vec[end];
    int left = beg, right = end - 1;

    for (int i = beg; i <= right && left <= right; i++)
    {
        if (vec[i] < num)
        {
            swap(vec, i, left++);
        }
        else if (vec[i] > num)
        {
            swap(vec, i, right--);
            i--;
        }
    }
    swap(vec, right + 1, end);
    dfs(vec, beg, left - 1);
    dfs(vec, right + 2, end);
}

void func2()
{
    dfs(vec, 0, vec.size() - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    func1();
    show(vec);
    
    return 0;
}