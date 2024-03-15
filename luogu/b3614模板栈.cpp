#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> vec;
    int curIdx;

public:
    Stack()
    {
        vec.resize(100010);
        this->curIdx = 0;
    }
    void push(T x)
    {
        // cout << x << endl;
        this->vec[curIdx++] = x;
    }
    void pop()
    {
        if (curIdx == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        curIdx--;
    }
    void query()
    {
        if (curIdx == 0)
        {
            cout << "Anguei!" << endl;
            return;
        }
        cout << vec[curIdx - 1] << endl;
    }
    void size()
    {
        cout << this->curIdx << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long T, n, x;
    string cmd;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Stack<long long> *stk = new Stack<long long>;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> cmd;
            if (cmd == "push")
            {
                cin >> x;
                stk->push(x);
            }
            else if (cmd == "pop")
                stk->pop();
            else if (cmd == "query")
                stk->query();
            else if (cmd == "size")
                stk->size();
        }
    }

    return 0;
}