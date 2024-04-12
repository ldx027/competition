#include <iostream>
#include <vector>
using namespace std;

struct Heap
{
    vector<int> vec;
    int size;
    Heap() { size = 0; }

    void swap(int a, int b)
    {
        if (a == b) return;
        vec[a] ^= vec[b];
        vec[b] ^= vec[a];
        vec[a] ^= vec[b];
    }

    void insert(int x)
    {
        vec.push_back(x);
        int idx = size++;
        while (vec[idx] > vec[(idx - 1) / 2])
        {
            swap(idx, (idx - 1) / 2);
            idx = (idx - 1) / 2;
        }
    }


    int top()
    {
        return vec[0];
    }

    void pop()
    {
        swap(0, --size);

        int idx = 0;
        int largest;
        while (idx * 2 + 1 < size)
        {
            largest = vec[idx] > vec[idx * 2 + 1] ? idx : idx * 2 + 1;
            largest = idx * 2 + 2 < size && vec[idx * 2 + 2] > vec[largest] ? idx * 2 + 2 : largest;
            if (largest == idx) break;
            swap(idx, largest);
            idx = largest;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, op, x;
    cin >> n;

    Heap heap;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            heap.insert(x);
        }
        else if (op == 2)
        {
            heap.pop();
        }
        else if (op == 3)
        {
            cout << heap.top() << endl;
        }
    }

    return 0;
}