#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    string name;
    unordered_set<int> st;
    int avg = 0;
};

bool cmp(Node &a, Node &b)
{
    return a.st.size() > b.st.size() || a.st.size() == b.st.size() && a.avg < b.avg;
}

vector<Node> vec;
void input(int idx)
{
    string name;
    int k;
    int sum = 0;
    cin >> name >> k;

    vec[idx].name = name;
    int x;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        vec[idx].st.insert(x);
        sum += x;
    }

    vec[idx].avg = sum / k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N);

    for (int i = 0; i < N; i++)
    {
        input(i);
    }
    sort(vec.begin(), vec.end(), cmp);
    cout << vec[0].name;
    for (int i = 1; i < 3; i++)
    {
        cout << " ";
        if (i >= vec.size())
        {
            cout << "-";
        }
        else 
        {
            cout << vec[i].name;
        }
    }

    return 0;
}