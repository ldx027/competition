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
    if (node == nullptr) return nullptr;
    if (node->val == x) return node;
    Node *fdL = find(node->left, x);
    if (fdL == nullptr) return find(node->right, x);
}

int dfs(Node *node)
{
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return node->val;
    int rst = 0;
    if (node->left != nullptr) rst += dfs(node->left);
    if (node->right != nullptr) rst += dfs(node->right);
    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int k;
    cin >> N >> k;
    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    Node *head = new Node(k);
    Node *node;

    int r, d, e;
    for (int i = 1; i < N; i++)
    {
        cin >> r >> d >> e;
        node = find(head, r);
        if (d == 0)
        {
            node->left = new Node(e);
        }
        else
        {
            node->right = new Node(e);
        }
    }

    cout << dfs(head) << endl;

    return 0;
}