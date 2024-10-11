#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #define debug

int n;
vector<int> bg, ed, buf;
vector<int> diff, sum;

void show(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n;

    bg.resize(n);
    ed.resize(n);
    buf.resize(n << 1);

    for (int i = 0; i < n; i++)
    {
        cin >> bg[i] >> ed[i];
        if (ed[i] < bg[i])
            ed[i] ^= bg[i] ^= ed[i] ^= bg[i];

        buf[i << 1] = bg[i];
        buf[(i << 1) + 1] = ed[i];
    }

    sort(buf.begin(), buf.end());
    buf.erase(unique(buf.begin(), buf.end()), buf.end());

#ifdef debug
    cout << "pos" << endl;
    show(bg);
    show(ed);

    cout << "buf" << endl;
    show(buf);
#endif

    diff.resize(buf.size(), 0);
    for (int i = 0; i < n; i++)
    {
        diff[lower_bound(buf.begin(), buf.end(), bg[i]) - buf.begin()]++;
        diff[lower_bound(buf.begin(), buf.end(), ed[i]) - buf.begin()]--;
    }

#ifdef debug
    cout << "diff" << endl;
    show(diff);
#endif

    sum.resize(buf.size(), 0);
    sum[0] = diff[0];
    for (int i = 1; i < sum.size(); i++)
        sum[i] = sum[i - 1] + diff[i];

#ifdef debug
    cout << "sum" << endl;
    show(sum);
#endif

    int ans = 0;
    for (int i = 0; i < sum.size() - 1; i++)
    {
        if (sum[i] > 0)
            ans += buf[i + 1] - buf[i];
    }

    cout << ans << endl;

    return 0;
}
