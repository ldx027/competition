#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

struct MonoQueue
{
    list<pair<int, int>> lst;
    bool (*cmp)(int, int);

    MonoQueue(bool (*cmp)(int, int))
    {
        this->cmp = cmp;
    }

    int cnt = 0;

    void slide()
    {
        cnt++;
        while (lst.size() > 0 && lst.begin()->second < cnt)
            lst.pop_front();
    }

    void push(int x, int idx)
    {
        cout << x << " " << idx << endl;
        lst.push_back({x, idx});
        while (lst.size() > 0 && !cmp(lst.begin()->first, x))
            lst.pop_front();
    }

    int front()
    {
        for (auto it = lst.begin(); it != lst.end(); it++)
            cout << it->first << " ";
        return lst.begin()->first;
    }
};

bool bigger(int x, int y) { return x > y; }
bool lower(int x, int y) { return x < y; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    MonoQueue greaterQue(bigger), smallerQue(lower);

    int n, k, x;
    cin >> n >> k;

    list<int> rst1, rst2;

    int i;
    for (i = 0; i < k; i++)
    {
        cin >> x;
        greaterQue.push(x, i);
        smallerQue.push(x, i);
    }

    rst1.push_back(greaterQue.front());
    rst2.push_back(smallerQue.front());

    for (; i < n; i++)
    {
        cin >> x;
        greaterQue.push(x, i);
        smallerQue.push(x, i);
        greaterQue.slide();
        smallerQue.slide();
        rst1.push_back(greaterQue.front());
        rst2.push_back(smallerQue.front());
    }

    for (auto it = rst1.begin(); it != rst1.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (auto it = rst2.begin(); it != rst2.end(); it++)
        cout << *it << " ";

    return 0;
}