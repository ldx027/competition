#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define NUM 16
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
public:
    Node(int _val)
    {
        this->val = _val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void funcFront(Node *node)
{
    cout << node->val << " ";
    if (node->left != nullptr) funcFront(node->left);
    if (node->right != nullptr) funcFront(node->right);
}

void funcMiddle(Node *node)
{
    if (node->left != nullptr) funcMiddle(node->left);
    cout << node->val << " ";
    if (node->right != nullptr) funcMiddle(node->right);
}

void funcBack(Node *node)
{
    if (node->left != nullptr) funcBack(node->left);
    if (node->right != nullptr) funcBack(node->right);
    cout << node->val << " ";
}

void front(Node *node)
{
    stack<Node*> stk;
    stk.push(node);
    while (!stk.empty())
    {
        Node* cur = stk.top();
        stk.pop();
        cout << cur->val << " ";
        if (cur->right != nullptr)
        {
            stk.push(cur->right);
        }
        if (cur->left != nullptr)
        {
            stk.push(cur->left);
        }
    }
    cout << endl;
}

void back(Node *node)
{
    stack<Node*> stk;
    stack<int> collect;
    stk.push(node);

    while (!stk.empty())
    {
        Node *cur = stk.top();
        stk.pop();
        collect.push(cur->val);
        if (cur->left != nullptr) stk.push(cur->left);
        if (cur->right != nullptr) stk.push(cur->right);
    }
    while (!collect.empty())
    {
        cout << collect.top() << " ";
        collect.pop();
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<Node*> vec;
    for (int i = 0; i < NUM; i++) vec.push_back(new Node(i));
    for (int i = 0; i < NUM; i++)
    {
        if (2 * i + 1 >= NUM) break;
        vec[i]->left = vec[2 * i + 1];
        if (2 * i + 2 >= NUM) break;
        vec[i]->right = vec[2 * i + 2];
    }

    funcFront(vec[0]);
    cout << endl;
    funcMiddle(vec[0]);
    cout << endl;
    funcBack(vec[0]);
    cout << endl;

    cout << endl;
    front(vec[0]);
    back(vec[0]);

    return 0;
}