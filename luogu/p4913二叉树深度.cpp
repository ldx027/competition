#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int id;
    Node *left;
    Node *right;

public:
    Node(int _id) : id(_id) 
    {
        this->left = nullptr;
        this->right = nullptr;
    }
};

int depth(Node *node)
{
    if (node == nullptr) return 0;
    return max(depth(node->left), depth(node->right)) + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<Node*> vec(1);
    for (int i = 1; i <= n; i++)
    {
        vec.push_back(new Node(i));
    }

    int l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        if (l != 0)
        {
            vec[i]->left = vec[l];
        }
        if (r != 0)
        {
            vec[i]->right = vec[r];
        }
    }
    
    cout << depth(vec[1]) << endl;;

    return 0;
}