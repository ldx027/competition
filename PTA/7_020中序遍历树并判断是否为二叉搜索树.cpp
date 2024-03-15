#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int _val) : val(_val)
    {
        left = right = nullptr;
    }
};

Node *find(Node *node, int x)
{
    if (node == nullptr)
        return nullptr;
    if (node->val == x)
        return node;
    Node *findInLeft = find(node->left, x);
    if (findInLeft != nullptr)
        return findInLeft;
    return find(node->right, x);
}

bool dfs(Node *node)
{
    bool yes = true;
    if (node->left != nullptr)
        yes = dfs(node->left) && (node->left->val < node->val) && yes;
    cout << node->val << endl;
    if (node->right != nullptr)
        yes = dfs(node->right) && (node->right->val > node->val) && yes;
    return yes;
}

int main()
{
    int N, k;
    cin >> N;
    if (N == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    cin >> k;
    Node *head = new Node(k);
    Node *node = nullptr;

    int r, d, e;
    for (int i = 1; i < N; i++)
    {
        cin >> r >> d >> e;
        node = find(head, r);
        if (d == 0)
            node->left = new Node(e);
        else if (d == 1)
            node->right = new Node(e);
    }
    bool yes = dfs(head);
    cout << (yes ? "Yes" : "No") << endl;

    return 0;
}