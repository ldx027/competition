#include <iostream>
#include <vector>
using namespace std;

vector<long long> vec;

void swap(vector<long long> &vec, int a, int b)
{
    long long temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

void show(vector<long long> vec)
{
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}

void quickSort(int beg, int end, int rank)
{
    if (beg >= end) return;
    int left = beg, right = end - 1;
    for (int i = beg; i <= right; i++)
    {
        if (vec[i] < vec[end]) swap(vec, i, left++);
        else if (vec[i] > vec[end]) swap(vec, i--, right--);
    }
    swap(vec, ++right, end);
    left--, right++;

    // show(vec);
    if (rank <= left) return quickSort(beg, left, rank);
    else if (rank > left && rank < right) return;
    else if (rank >= right) return quickSort(right, end, rank);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, idx;
    cin >> n >> idx;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    quickSort(0, vec.size() - 1, idx);
    cout << vec[idx] << endl;
    // show(vec);

    return 0;
}