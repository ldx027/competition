#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string str;
    Node *left;
    Node *right;
    
    Node(string str)
    {
        this->str = str;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void deal(Node *node, string *zx, int *n = 0)
{
    char c =  (*zx)[*n];
    *n += 1;
    int idx = node->str.find(c);
    if (idx > 0)
    {
        node->left = new Node(node->str.substr(0, idx));
        deal(node->left, zx, n);
    }
    if (node->str.size() - idx > 1)
    {
        node->right = new Node(node->str.substr(idx + 1));
        deal(node->right, zx, n);
    }
    node->str = c;
}

void show(Node *node)
{
    if (node->left != nullptr) show(node->left);
    if (node->right != nullptr) show(node->right);
    cout << node->str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string qx, zx;
    cin >> qx >> zx;

    int idx = 0;
    Node *baseNode = new Node(qx);
    deal(baseNode, &zx, &idx);
    show(baseNode);

    return 0;
}