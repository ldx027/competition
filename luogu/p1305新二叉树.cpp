#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    char val;
    Node *left;
    Node *right;
    Node(char c) : val(c)
    {
        left = right = nullptr;
    }
};

void show(Node *head)
{
    if (head == nullptr) return;
    cout << head->val << "";
    show(head->left);
    show(head->right);
}

vector<Node*> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(26);
    for (int i = 0; i < 26; i++) vec[i] = new Node(i + 'a');

    char u, v;
    char head = '?';
    for (int i = 0; i < N; i++)
    {
        cin >> u;
        if (head == '?') head = u;
        cin >> v;
        if (v != '*')
        {
            vec[u - 'a']->left = vec[v - 'a'];
        }
        cin >> v;
        if (v != '*')
        {
            vec[u - 'a']->right = vec[v - 'a'];
        }
    }
    show(vec[head - 'a']);

    return 0;
}