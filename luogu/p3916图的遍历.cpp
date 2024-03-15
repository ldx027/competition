#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node
{
    int id;
    int max;
    vector<Node*> next;
    Node(int _id)
    {
        this->id = _id;
        this->next = vector<Node*>();
        max = 0;
    }
};

void func(Node *node, set<Node*> *st, int N)
{
    st->insert(node);
    if (node->max == 0)
        node->max = N;
    // cout << node->id << "is" << N << endl;
    for (int i = 0; i < node->next.size(); i++)
    {
        if (st->count(node->next[i]) != 0) continue;
        if (node->next[i]->max == 0)
        {
            func(node->next[i], st, N);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Node*> vec(N);
    for (int i = 0; i < N; i++)
    {
        vec[i] = new Node(i + 1);
    }

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        vec[b - 1]->next.push_back(vec[a - 1]);
    }


    for (int i = N - 1; i >= 0; i--)
    {
        set<Node*> st;
        func(vec[i], &st, vec[i]->id);
    }

    for (int i = 0; i < N; i++)
    {
        cout << vec[i]->max << " ";
    }

    return 0;
}