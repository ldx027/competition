#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> vec;
    int cap;
    int size;

public:
    Heap(int cap)
    {
        this->cap = cap;
        this->vec.resize(cap);
        this->size = 0;
    }

    void swap(int a, int b)
    {
        vec[a] ^= vec[b];
        vec[b] ^= vec[a];
        vec[a] ^= vec[b];
    }

    void show()
    {
        if (size > 0)
            cout << vec[0];
        for (int i = 1; i < size; i++)
            cout << " " << vec[i];
        cout << endl;
    }

    void insert(int x)
    {
        if (size >= cap)
            return;
        vec[size++] = x;
        int idx = size - 1;
        while (vec[idx] < vec[(idx - 1) / 2])
        {
            swap(idx, (idx - 1) / 2);
            idx = (idx - 1) / 2;
        }
    }

    void pop()
    {
        if (size <= 0) return;
        swap(0, --size);
        int idx = 0;
        while (2 * idx + 1 < size)
        {
            int smallest = 2 * idx + 2 < size && vec[2 * idx + 2] < vec[2 * idx + 1] ? 2 * idx + 2 : 2 * idx + 1;
            smallest = vec[smallest] < vec[idx] ? smallest : idx;
            if (idx == smallest) break;
            swap(idx, smallest);
            idx = smallest;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    Heap heap(N);

    int cmd, x;
    for (int i = 0; i < K; i++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> x;
            heap.insert(x);
        }
        else if (cmd == -1)
        {
            heap.pop();
        }
        heap.show();
    }

    int M;
    cin >> M;
    Heap heap2(M);

    for (int i = 0; i < M; i++)
    {
        cin >> x;
        heap2.insert(x);
    }
    heap2.show();


    return 0;
}