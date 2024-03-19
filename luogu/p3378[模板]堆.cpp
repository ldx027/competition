#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void swap(int a, int b)
{
    if (a == b) return;
    heap[a] ^= heap[b] ^= heap[a];
}

void insert(int x)
{
    heap.push_back(x);
    int idx = heap.size() - 1;
    while (heap[idx] > heap[(idx - 1) / 2])
    {
        swap(idx, (idx - 1) / 2);
        idx = (idx - 1) / 2;
    }
}

void pop()
{
    swap(0, heap.size() - 1);
    heap.pop_back();
    int idx = 0;

    while(1)
    {
        if (idx * 2 + 1 >= heap.size()) break;
        int largest = heap[idx] > heap[idx * 2 + 1] ? idx : (idx * 2 + 1);
        largest = ((idx * 2 + 2) < heap.size() && heap[idx * 2 + 2] > heap[largest]) ? (idx * 2 + 2) : largest;
        if (idx == largest) break;
        swap(idx, largest);
        idx = largest;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int op, x;
    for (int i = 0; i < N; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            insert(-x);
        }
        else if (op == 2)
        {
            cout << -heap[0] << endl;
        }
        else if (op == 3)
        {
            pop();
        }
    }

    return 0;
}