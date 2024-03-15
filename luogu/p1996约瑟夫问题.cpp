#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    Node *next;

    Node (int _id) : id(_id) {}
};

Node *create(Node *base, int id)
{
    Node *newNode = new Node(id);
    if (base != nullptr)
    {
        base->next = newNode;
    }
    newNode->next = nullptr;
    
    return newNode;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int idx = 1;
    Node *first = create(nullptr, idx++);
    Node *now = first;
    for (int i = 0; i < n - 1; i++)
    {
        now = create(now, idx++);
    }
    now->next = first;

    idx = 1;
    while (now->next != now)
    {
        for (int i = 1; i < m; i++)
        {
            now = now->next;
        }
        cout << now->next->id << " ";
        now->next = now->next->next;
    }
    cout << now->next->id;

    return 0;
}