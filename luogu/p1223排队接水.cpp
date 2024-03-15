#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int id;
    int t;
};

bool cmp(Node a, Node b)
{
    return a.t < b.t;
}

vector<Node> vec;
int main()
{
    int N;
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++)
    {
        vec[i].id = i + 1;
        cin >> vec[i].t;
    }
    sort(vec.begin(), vec.end(), cmp);

    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += vec[i].t * (N - 1 - i);
    }

    for (int i = 0; i < N; i++)
        cout << vec[i].id << " ";
    printf("\n%.2f\n", ans / N);

    return 0;
}