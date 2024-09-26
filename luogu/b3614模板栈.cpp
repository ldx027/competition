#include <iostream>
#include <string>
using namespace std;

#define ll unsigned long long

template <typename T>
struct Node
{
    T *val;
    Node<T> *prev;
    Node<T> *nxt;

    Node()
    {
        val = nullptr;
        prev = nullptr;
        nxt = nullptr;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *head;
    Node<T> *cur;
    ll size;

public:
    Stack()
    {
        head = new Node<T>;
        cur = head;
        size = 0;
    }

    void push(T val)
    {
        cur->nxt = new Node<T>;
        cur->nxt->prev = cur;
        cur = cur->nxt;
        cur->val = new T;
        *cur->val = val;
        size++;
    }

    T top()
    {
        return *cur->val;
    }

    void pop()
    {
        cur = cur->prev;
        delete cur->nxt->val;
        delete cur->nxt;
        cur->nxt = nullptr;
        size--;
    }

    ll getSize()
    {
        return size;
    }

};

int main()
{
    ll T;
    cin >> T;

    string cmd;
    ll x;

    while (T--)
    {
        ll n;
        cin >> n;
        Stack<ll> stk;

        for (int i = 0; i < n; i++)
        {
            cin >> cmd;
            
            if (cmd == "push")
            {
                cin >> x;
                stk.push(x);
            }

            else if (cmd == "query")
            {
                if (stk.getSize() == 0)
                    cout << "Anguei!" << endl;
                else
                    cout << stk.top() << endl;
            }

            else if (cmd == "pop")
            {
                if (stk.getSize() == 0)
                    cout << "Empty" << endl;
                else
                    stk.pop();
            }

            else if (cmd == "size")
                cout << stk.getSize() << endl;
        }

        // while (stk.getSize())
        //     stk.pop();
    }

    return 0;
}