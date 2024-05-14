#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isTree(const vector<int> &vec, int L, int R)
{
    if (L >= R) return true;
    int mid = L + 1;
    while (mid + 1 < R && vec[mid + 1] < vec[L]) mid++;
    for  (int i = mid + 1; i <= R; i++) if (vec[i] < vec[L]) return false;
    return isTree(vec, L + 1, mid) && isTree(vec, mid + 1, R);
}

bool isMirTree(const vector<int> &vec, int L, int R)
{
    if (L >= R) return true;
    int mid = L + 1;
    while (mid + 1 < R && vec[mid + 1] >= vec[L]) mid++;
    for  (int i = mid + 1; i <= R; i++) if (vec[i] >= vec[L]) return false;
    return isMirTree(vec, L + 1, mid) && isMirTree(vec, mid + 1, R);
}

bool flg = false;

void showTree(const vector<int> &vec, int L, int R)
{
    if (L > R) return;
    if (L == R)
    {
        if (flg) cout << " ";
        cout << vec[L];
        flg = true;
        return;
    }

    int mid = L + 1;
    while (mid + 1 < R && vec[mid + 1] < vec[L]) mid++;

    showTree(vec, L + 1, mid);
    showTree(vec, mid + 1, R);
    if (flg) cout << " ";
    cout << vec[L];
    flg = true;
}

void showMirTree(const vector<int> &vec, int L, int R)
{
    if (L > R) return;
    if (L == R)
    {
        if (flg) cout << " ";
        cout << vec[L];
        flg = true;
        return;
    }

    int mid = L + 1;
    while (mid < R && vec[mid + 1] >= vec[L]) mid++;

    showMirTree(vec, L + 1, mid);
    showMirTree(vec, mid + 1, R);
    if (flg) cout << " ";
    cout << vec[L];
    flg = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    // cout << isTree(vec, 0, vec.size() - 1) << endl;
    // cout << isMirTree(vec, 0, vec.size() - 1);

    if (isTree(vec, 0, N - 1))
    {
        cout << "YES\n";
        showTree(vec, 0, N - 1);
    }
    else if (isMirTree(vec, 0, N - 1))
    {
        cout << "YES\n";
        showMirTree(vec, 0, N - 1);
    }
    else cout << "NO" << endl;

    return 0;
}