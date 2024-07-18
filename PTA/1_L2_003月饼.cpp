#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    double D;
    cin >> N >> D;

    vector<double> cunliang(N);
    vector<double> shoujia(N);

    for (int i = 0; i < N; i++) cin >> cunliang[i];
    for (int i = 0; i < N; i++) cin >> shoujia[i];

    priority_queue<pair<double, int>> heap;
    for (int i = 0; i < N; i++) heap.push({shoujia[i] / cunliang[i], i});

    double sum = 0;
    while (D > 0 && !heap.empty())
    {
        sum += min(D, cunliang[heap.top().second]) * heap.top().first;
        D -= cunliang[heap.top().second];
        heap.pop();
    }

    printf("%.2lf", sum);

    return 0;
}