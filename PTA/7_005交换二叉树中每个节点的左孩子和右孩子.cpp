#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    char c;
    int state = 1;
    Node *father = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;

    Node()
    {
        state = 1;
        father = left = right = nullptr;
    }
};

void show1(Node *node)
{
    if (node == nullptr)
        return;
    show1(node->left);
    cout << node->c;
    show1(node->right);
}

void show2(Node *node)
{
    if (node == nullptr)
        return;
    show2(node->right);
    cout << node->c;
    show2(node->left);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    Node *head = new Node;
    Node *node = head;
    head->c = str[0];

    for (int i = 1; i < str.size(); i++)
    {
        // cout << i << endl;
        if (str[i] == '#')
        {
            node->state++;
            while (node->state >= 3)
            {
                if (node->father == nullptr)
                    break;
                node = node->father;
            }
        }
        else
        {
            if (node->state == 1)
            {
                node->state++;
                node->left = new Node;
                node->left->father = node;
                node = node->left;
            }
            else if (node->state == 2)
            {
                node->state++;
                node->right = new Node;
                node->right->father = node;
                node = node->right;
            }
            node->c = str[i];
        }
    }

    show1(head);
    cout << endl;
    show2(head);

    return 0;
}