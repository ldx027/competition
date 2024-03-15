#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line
{
    int beg, end;
};

bool cmp(Line a, Line b)
{
    return a.end < b.end;
}

vector<Line> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i].beg >> vec[i].end;
    sort(vec.begin(), vec.end(), cmp);

    int time = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (vec[i].beg >= time)
        {
            time = vec[i].end;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}