#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int val;
    vector<int> vec;
    Node *left = nullptr;
    Node *right = nullptr;
};

int cnt = 0;
void deal(Node *node, const vector<int> &frt, int &cnt)
{
    int idx = find(node->vec.begin(), node->vec.end(), frt[cnt++]) - node->vec.begin();
    cout << idx << endl;
    node->val = frt[idx];
    if (idx > 0)
    {
        cout << "left" << endl;
        node->left = new Node;
        node->left->vec.assign(node->vec.begin(), node->vec.begin() + idx - 1);
        deal(node->left, frt, cnt);
    }
    if (node->vec.size() - idx > 1)
    {
        cout << "right" << endl;
        node->right = new Node;
        node->right->vec.assign(node->vec.begin() + idx + 1, node->vec.end());
        deal(node->right, frt, cnt);
    }
}

vector<int> mid;
vector<int> frt;
queue<Node*> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    mid.resize(N);
    frt.resize(N);
    for (int i = 0; i < N; i++) cin >> mid[i];
    for (int i = 0; i < N; i++) cin >> frt[i];

    Node *head = new Node;
    que.push(head);
    head->vec = mid;
    deal(head, frt, cnt);

    Node *node;
    while (!que.empty())
    {
        node = que.front();
        que.pop();
        cout << node->val << " ";
        if (node->left != nullptr) que.push(node->left);
        if (node->right != nullptr) que.push(node->right);
    }

    return 0;
}