#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *random;
    Node *next;
public:
    Node(int _val)
    {
        val = _val;
        random = nullptr;
        next = nullptr;
    }
};

Node *func1(Node *baseNode)
{
    unordered_map<Node*, Node*> mp;
    Node *now = baseNode;
    Node *newBase = new Node(now->val);
    mp.insert(now, newBase);
    now = now->next;
    while (now != nullptr)
    {
        Node *newNode = new Node(now->val);
        mp.insert(now, newNode);
        now = now->next;
    }

    Node *now1 = baseNode;
    Node *now2 = newBase;
    while (now1 != nullptr)
    {
        if (now1->random != nullptr)
        {
            now2->random = mp[now1]);
        }
    }
}

int main()
{
    return 0;
}