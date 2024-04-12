#include <iostream>
#include <vector>
#include <string>
using namespace std;

int idx = 0;
string fr, mid;

struct Node
{
    Node *left, *right;
    char val;
    string str;

    Node()
    {
        left = right = nullptr;
        val = '\0';
    }

    void dfs()
    {
        int div = str.find(fr[idx++]);
        val = str[div];
        if (div > 0)
        {
            left = new Node;
            left->str = str.substr(0, div);
            left->dfs();
        }
        if (div < str.size() - 1)
        {
            right = new Node;
            right->str = str.substr(div + 1);
            right->dfs();
        }
    }
};

void show(Node *node)
{
    if (node == nullptr) return;
    show(node->left);
    show(node->right);
    cout << node->val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> fr >> mid;

    Node head;
    head.str = mid;
    head.dfs();

    show(&head);

    return 0;
}