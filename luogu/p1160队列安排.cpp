#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void show(list<int> *lst)
{
    // cout << "lst";
    for (auto it = lst->begin(); it != lst->end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 用空间换时间 将索引存起来规避链表随机读取速度慢问题
list<int>::iterator its[100000];
bool have[100000] = { false };
int main()
{
    ios::sync_with_stdio(0);
    int N;
    cin >> N;

    list<int> lst;
    lst.push_back(1); 
    its[1] = lst.begin();
    have[1] = true;
    
    for (int i = 2; i <= N; i++)
    {
        int k ,p;
        cin >> k >> p;
        auto it = its[k];
        if (p) it++;
        its[i] = lst.insert(it, i);
        have[i] = true;
        // show(&lst);
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x; 
        if (have[x])
        {
            lst.erase(its[x]);
            have[x] = false;
            // show(&lst);
        }
    }

    show(&lst);

    return 0;
}