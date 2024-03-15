#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    long long id;
    vector<Node*> next;

    Node(long long _id) : id(_id) {}
};

void dfs(Node *node, set<Node*> *st)
{
    st->insert(node);
    cout << node->id << " ";
    for (long long i = 0; i < node->next.size(); i++)
    {
        if (st->count(node->next[i]) != 0) continue;
        dfs(node->next[i], st);
    }
}

bool smaller(Node* a, Node *b)
{
    return a->id < b->id;
}

void bfs(Node *node)
{
    set<Node*> st;
    queue<Node*> que;
    que.push(node);
    st.insert(node);

    while (!que.empty())
    {
        cout << que.front()->id << " ";
        st.insert(que.front());
        for (int i = 0; i < que.front()->next.size(); i++)
        {
            if (st.count(que.front()->next[i]) != 0) continue;
            que.push(que.front()->next[i]);
            st.insert(que.front()->next[i]);
        }
        que.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;
    cin >> n >> m;

    vector<Node*> vec(n);
    for (long long i = 0; i < n; i++)
    {
        vec[i] = new Node(i + 1);
    }

    long long a, b; 
    for (long long i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a - 1]->next.push_back(vec[b - 1]);
    }

    for (long long i = 0; i < n; i++)
    {
        sort(vec[i]->next.begin(), vec[i]->next.end(), smaller);
    }

    set<Node*> st;
    dfs(vec[0], &st);
    cout << endl;
    bfs(vec[0]);
    cout << endl;

    return 0;
}