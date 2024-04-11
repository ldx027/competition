#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct Node
{
    Node *left, *right;
    char val;

    Node(char c = '\0') : val(c) { left = right = nullptr; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string fr, mid;
    cin >> n >> fr >> mid;

    int idx = 0;
    stack<Node*> stk;

    Node *head = new Node;
    stk.push(head);

    while (!stk.empty())
    {
        Node *cur = stk.top();
        stk.pop();
    }
}