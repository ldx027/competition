#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

list<int> lst;
vector<int> vec;

void show()
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Push(int x)
{
    lst.push_back(x);
    auto it = lower_bound(vec.begin(), vec.end(), x);
    vec.insert(it, x);
    // show();
}

void Mid()
{
    if (vec.size() == 0)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << vec[(vec.size() - 1) / 2] << endl;
        // auto it = lst.begin();
        // while (*it != vec[vec.size() / 2]) it++;
        // lst.erase(it);
        // vec.erase(vec.begin() + vec.size() / 2);
    }
}

void Pop()
{
    if (vec.size() == 0)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        int x = lst.back();
        cout << x << endl;
        auto it = lower_bound(vec.begin(), vec.end(), x);
        vec.erase(it);
        lst.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string cmd;
    int x;
    while (N--)
    {
        cin >> cmd;
        if (cmd == "Push" && cin >> x)
            Push(x);
        else if (cmd == "PeekMedian")
            Mid();
        else if (cmd == "Pop")
            Pop();
    }

    return 0;
}