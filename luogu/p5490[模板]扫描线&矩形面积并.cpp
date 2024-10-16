#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #define debug
#define ll long long

struct Line
{
    ll y, l, r, mark;
    Line() {}
    Line(ll _y, ll _l, ll _r, ll _m) : y(_y), l(_l), r(_r), mark(_m) {}
};
bool cmp(Line a, Line b) { return a.y < b.y; }

ll n, m;
vector<ll> len, tag, buf;
vector<Line> lines;

void pushUp(ll idx, ll l, ll r)
{
    if (tag[idx])
        len[idx] = buf[r + 1] - buf[l];
    else
        len[idx] = len[idx << 1] + len[idx << 1 | 1];
}

void update(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        tag[idx] += val;
        pushUp(idx, pl, pr);
        return;
    }

    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l)
        update(l, r, idx << 1, pl, mid, val);
    if (mid < r)
        update(l, r, idx << 1 | 1, mid + 1, pr, val);
    pushUp(idx, pl, pr);
}

int main()
{
    cin >> n;
    buf.resize(n << 1);
    lines.resize(n << 1);

    ll x1, y1, x2, y2;
    for (ll i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i << 1] = Line(y1, x1, x2, 1);
        lines[i << 1 | 1] = Line(y2, x1, x2, -1);
        buf[i << 1] = x1;
        buf[i << 1 | 1] = x2;
    }

    sort(lines.begin(), lines.end(), cmp);
    sort(buf.begin(), buf.end());
    buf.erase(unique(buf.begin(), buf.end()), buf.end());
    m = buf.size();

    len.resize(m << 3, 0);
    tag.resize(m << 3, 0);

    for (ll i = 0; i < lines.size(); i++)
    {
        lines[i].l = lower_bound(buf.begin(), buf.end(), lines[i].l) - buf.begin();
        lines[i].r = lower_bound(buf.begin(), buf.end(), lines[i].r) - buf.begin() - 1;
    }

#ifdef debug
    cout << "buf" << endl;
    for (ll i = 0; i < m; i++)
        cout << buf[i] << " ";
    cout << endl;

    cout << "lines" << endl;
    for (ll i = 0; i < lines.size(); i++)
        cout << lines[i].y << " " << lines[i].l << " " << lines[i].r << endl;
    cout << endl;
#endif

    ll rst = 0;
    for (ll i = 0; i < lines.size() - 1; i++)
    {
        update(lines[i].l, lines[i].r, 1, 0, m - 1, lines[i].mark);
#ifdef debug
        cout << "len";
        cout << len[1] << endl;
#endif
        rst += len[1] * (lines[i + 1].y - lines[i].y);
    }

    printf("%lld", rst);

    return 0;
}