#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// #define debug

struct Cow
{
    int x, id;
};

bool cmp(Cow a, Cow b)
{
    return a.x < b.x;
}

int main()
{
    int n;
    cin >> n;

    vector<Cow> cows(n);
    vector<int> ids(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cows[i].x >> cows[i].id;
        ids[i] = cows[i].id;
    }

    sort(ids.begin(), ids.end());
    sort(cows.begin(), cows.end(), cmp);

    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    for (int i = 0; i < n; i++)
        cows[i].id = lower_bound(ids.begin(), ids.end(), cows[i].id) - ids.begin();

#ifdef debug
    cout << "num of kind ";
    cout << ids.size() << endl;

    cout << "kind" << endl;    
    for (int i = 0; i < ids.size(); i++)
        cout << ids[i] << " ";
    cout << endl;

    cout << "after sort" << endl;
    for (int i = 0; i < n; i++)
        cout << cows[i].x << " " << cows[i].id << endl;
#endif
    
    int ans = 0x3f3f3f3f;
    vector<int> kind(ids.size(), 0);
    queue<Cow> que;
    for (int i = 0; i < n; i++)
    {
        que.push(cows[i]);
        kind[cows[i].id]++;

        while (!que.empty() && kind[que.front().id] > 1)
            kind[que.front().id]--, que.pop();
        
        bool flg = true;
        for (int j = 0; j < kind.size(); j++)
            if (!kind[j])
                flg = false;
        
        if (flg)
            ans = min(ans, cows[i].x - que.front().x);
    }

    cout << ans << endl;
    
    return 0;
}
