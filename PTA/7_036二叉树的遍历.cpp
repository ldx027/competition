#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    int left;
    int right;
};

bool flg = false;
void func1(vector<Node> &vec, int x)
{
    if (x == -1) return;
    if (flg) cout << " ";
    cout << vec[x].val;
    flg = 1;
    func1(vec, vec[x].left);
    func1(vec, vec[x].right);
}
void func2(vector<Node> &vec, int x)
{
    if (x == -1) return;
    func2(vec, vec[x].left);
    if (flg) cout << " ";
    cout << vec[x].val;
    flg = 1;
    func2(vec, vec[x].right);
}
void func3(vector<Node> &vec, int x)
{
    if (x == -1) return;
    func3(vec, vec[x].left);
    func3(vec, vec[x].right);
    if (flg) cout << " ";
    cout << vec[x].val;
    flg = 1;
}

vector<Node> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N + 1);
    int u, v, w;
    for (int i = 1; i <= N; i++)
    {
        cin >> u >> v >> w;
        vec[i] = {u, v, w};
    }

    func1(vec, 1);
    cout << endl;
    flg = 0;
    func2(vec, 1);
    cout << endl;
    flg = 0;
    func3(vec, 1);

    return 0;
}