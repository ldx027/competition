#include <iostream>
#include <queue>
using namespace std;

#define inf 2147483647

struct Node
{
    int val;
    int num;
    Node *pre;
    Node *left;
    Node *right;
    Node(int _val) : val(_val)
    {
        this->num = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insert(Node *head, int x)
{
    Node *cur = head;
    while (cur->val > x && cur->left != nullptr || cur->val < x && cur->right != nullptr)
    {
        if (cur->val > x)
            cur = cur->left;
        else if (cur->val < x)
            cur = cur->right;
    }
    if (cur->val == x)
    {
        cur->num++;
    }
    else if (cur->val < x)
    {
        cur->right = new Node(x);
        cur->right->pre = cur;
    }
    else if (cur->val > x)
    {
        cur->left = new Node(x);
        cur->left->pre = cur;
    }
}

int rank(Node *node)
{
    if (node->left == nullptr) return 1;
    Node *cur = node->left;
    queue<Node*> que;
    que.push(cur);
    
    int rst = 1;
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        rst += cur->num;
        if (cur->left != nullptr) que.push(cur->left);
        if (cur->right != nullptr) que.push(cur->right);
    }

    return rst;
}

int fr(Node *head, int x)
{
    Node *cur = head;
    while (cur->val >= x)
    {
        if (cur->left == nullptr) return -inf;
        cur = cur->left;
    }

    while (cur->right != nullptr) cur = cur->right;
    
    return cur->val;
}

int ne(Node *head, int x)
{
    Node *cur = head;
    while (cur->val <= x)
    {
        if (cur->right == nullptr) return inf;
        cur = cur->right;
    }

    while (cur->left != nullptr) cur = cur->left;
    
    return cur->val;
}

int xRank(Node *head, int x)
{
    Node *cur = head;
    while (cur->num)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}