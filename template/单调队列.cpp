#include <iostream>
#include <list>
#include <utility>
using namespace std;

struct MonoQue
{
    list<pair<int, int>> lst;
    bool (*cmp)(int, int);
    int cnt = 0;

    MonoQue(bool (*_cmp)(int, int)) : cmp(_cmp) {}

    void push(int x, int idx)
    {
        while (lst.size() > 0 && cmp(lst.rbegin()->first, x))
            lst.pop_back();
        lst.push_back({x, idx});
    }

    void slide()
    {
        cnt++;
        while (lst.size() > 0 && lst.begin()->second < cnt)
            lst.pop_front();
    }

    int front() { return lst.begin()->first; }
};

bool bigger(int x, int y) { return x > y; }
bool smaller(int x, int y) { return x < y; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    MonoQue biggerQue(bigger);
    MonoQue smallerQue(smaller);

    list<int> rst1, rst2;

    int n, k;
    cin >> n >> k;

    int idx = 0;
    int x;
    while (idx < k)
    {
        cin >> x;
        biggerQue.push(x, idx);
        smallerQue.push(x, idx);
        idx++;
    }

    rst1.push_back(biggerQue.front());
    rst2.push_back(smallerQue.front());

    while (idx < n)
    {
        cin >> x;
        biggerQue.push(x, idx);
        smallerQue.push(x, idx);
        biggerQue.slide();
        smallerQue.slide();
        rst1.push_back(biggerQue.front());
        rst2.push_back(smallerQue.front());
        idx++;
    }

    for (auto it = rst1.begin(); it != rst1.end(); it++) cout << *it << " ";
    cout << endl;
    for (auto it = rst2.begin(); it != rst2.end(); it++) cout << *it << " ";
    cout << endl;

    return 0;
}