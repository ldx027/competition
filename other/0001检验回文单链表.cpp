#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
public:
    Node()
    {
        val = 0;
        next = nullptr;
    }
    Node(int _val) : val(_val) 
    {
        next = nullptr;
    }
    
    Node *create(int val)
    {
        Node *newNode = new Node(val);
        this->next = newNode;
    }
};

Node *reverse(Node* base)
{
    if (base->next == nullptr) return base;
    Node *now = base->next;
    Node *next = base->next->next;
    Node *prev = base;
    base->next = nullptr;
    while (next != nullptr)
    {   
        now->next = prev;
        prev = now;
        now = next;
        next = next->next;
    }
    now->next = prev;

    return now;
}

bool func2(Node *base)
{
    Node *itf = base;
    Node *its = base;
    while (1)
    {
        itf = itf->next;
        if (itf == nullptr) break;
        itf = itf->next;
        if (itf == nullptr) break;
        its = its->next;
    }
    Node *itH = base;
    Node *itT = reverse(its);

    while (itH != nullptr)
    {
        if (itH->val != itT->val)
        {
            return false;
        }
        itH = itH->next;
        itT = itT->next;
    }

    return true;
}



bool func1(Node *base)
{
    stack<int> stk;
    Node *its = base;
    Node *itf = base;
    while (1)
    {
        stk.push(its->val);
        itf = itf->next;
        if (itf == nullptr) break;
        itf = itf->next;
        if (itf == nullptr) break;
        its = its->next;
    }
    its = its->next;
    while (!stk.empty() && its != nullptr && stk.top() == its->val)
    {
        its = its->next;
        stk.pop();
    }

    return stk.empty() && its == nullptr;
}

int main()
{
     int n;
     cin >> n;
     int x;
     cin >> x;
     Node *base = new Node(x);
     Node *now = base;
     for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        now = now->create(x);
    }
    cout << func1(base) << endl;
    cout << func2(base) << endl;

    return 0;
}