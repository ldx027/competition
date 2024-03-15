#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
public:
    Node(int _val)
    {
        this->val = _val;
        this->next = nullptr;
    }
};

Node *findLoop(Node *head)
{
    Node *itf = head;
    Node *its = head;
    while (itf != its)
    {
        if (itf->next == nullptr || itf->next->next == nullptr) return nullptr;
        itf = itf->next->next;
        its = its->next;
    }
    itf = head;
    while (itf != its)
    {
        itf = itf->next;
        its = its->next;
    }

    return its;
}

int main()
{
    vector<Node*> vec1;
    for (int i = 0; i < 10; i++)
    {
        vec1.push_back(new Node(i));
        if (i == 0) continue;
        vec1[i - 1]->next = vec1[i];
    }
    
    vector<Node*> vec2;
    for (int i = 0; i < 10; i++)
    {
        vec2.push_back(new Node(i));
        if (i == 0) continue;
        vec2[i - 1]->next = vec2[i];
    }
    vec2[9]->next = vec2[6];

    Node *node1 = findLoop(vec1[0]);
    Node *node2 = findLoop(vec2[0]);

    if (node1 == nullptr)
    {
        cout << "list havn't loop" << endl;
    }
    else
    {
        cout << node1->val << endl;
    }

    if (node2 == nullptr)
    {
        cout << "list havn't loop" << endl;
    }
    else
    {
        cout << node2->val << endl;
    }

    return 0;
}