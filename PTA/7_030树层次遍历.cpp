#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *father;
    vector<Node*> child;
    Node(int _val) : val(_val)
    {
        father = nullptr;
    }
};

queue<Node*> que;
void show()
{
    while (!que.empty())
    {
        Node *node = que.front();
        que.pop();
        cout << node->val << " ";
        for (auto it = node->child.begin(); it != node->child.end(); it++)
        {
            que.push(*it);
        }
    }
}

int main()
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *cur = head;
    que.push(head);

    while (cur != nullptr)
    {
        cin >> x;
        if (x == 0) cur = cur->father;
        else
        {
            cur->child.push_back(new Node(x));
            (*cur->child.rbegin())->father = cur;
            cur = *cur->child.rbegin();
        }
    }

    show();

    return 0;
}