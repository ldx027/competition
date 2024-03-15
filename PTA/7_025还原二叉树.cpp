#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char c;
    string str;
    Node *left;
    Node *right;
    Node(string _str) : str(_str)
    {
        left = right = nullptr;
    }
};

int idx = 0;
void dfs(Node *node, string qx)
{
    if (node->str.size() == 0 || idx == qx.size())
        return;

    int i = node->str.find(qx[idx]);
    node->c = node->str[i];
    idx++;
    if (i > 0)
    {
        node->left = new Node(node->str.substr(0, i));
        dfs(node->left, qx);
    }
    if (i < node->str.size() - 1)
    {
        node->right = new Node(node->str.substr(i + 1));
        dfs(node->right, qx);
    }
}

int deaph(Node *node)
{
    if (node == nullptr) return 0;
    return 1 + max(deaph(node->left), deaph(node->right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string qx;
    string zx;
    cin >> qx >> zx;

    Node *head = new Node(zx);
    dfs(head, qx);
    cout << deaph(head) << endl;
    
    return 0;
}