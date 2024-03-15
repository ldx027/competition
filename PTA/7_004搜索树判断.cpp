#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
bool isMor;

bool isTree(int beg, int end)
{
    // cout << beg << " " << end << endl;
    if (end <= beg)
        return true;
    int idx = beg;
    for (; idx < end && (idx == beg || vec[idx + 1] < vec[beg]); idx++)
        ;
    int mid = idx++;
    // cout << "mid" << mid << endl;
    for (; idx <= end; idx++)
        if (vec[idx] < vec[beg])
            return false;

    return isTree(beg + 1, mid) && isTree(mid + 1, end);
}

bool isMorTree(int beg, int end)
{
    if (end <= beg)
        return true;
    int idx = beg;
    for (; idx + 1 <= end && (idx == beg || vec[idx + 1] >= vec[beg]); idx++)
        ;
    int mid = idx;
    for (; idx <= end; idx++)
        if (vec[idx] >= vec[beg])
            return false;

    return isTree(beg + 1, mid) && isTree(mid + 1, end);
}

bool flg = false;
void showTree(int beg, int end)
{
    if (end < beg)
        return;
    int idx = beg;
    for (; idx + 1 <= end && (idx == beg || vec[idx + 1] < vec[beg]); idx++);
    showTree(beg + 1, idx);
    showTree(idx + 1, end);
    if (flg) cout << " ";
    flg = 1;
    cout << vec[beg];
}

void showMorTree(int beg, int end)
{
    if (end < beg)
        return;
    if (end == beg)
    {
        if (flg) cout << " ";
        cout << vec[beg];
        flg = 1;
        return;
    }
    int idx = beg;
    for (; idx + 1 <= end && (idx == beg || vec[idx + 1] >= vec[beg]); idx++);
    showTree(beg + 1, idx);
    showTree(idx + 1, end);
    if (flg) cout << " ";
    flg = 1;
    cout << vec[beg];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    if (N == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    vec.resize(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    if (N == 1)
    {
        cout << "YES" << endl;
        return 0;
    }

    isMor = vec[1] >= vec[0];

    if (!isMor)
    {
        if (!isTree(0, N - 1))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            showTree(0, N - 1);
        }
    }
    else
    {
        if (!isMorTree(0, N - 1))
        {
            cout << "NO" << endl;
            showMorTree(0, N - 1);
        }
    }

    return 0;
}