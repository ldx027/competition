#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Dancer
{
    int val;
    Dancer *prev;
    Dancer *next;
    Dancer()
    {
        prev = next = nullptr;
    }
};

struct Node
{
    int val;
    Dancer *a, *b;
    bool operator <(const Node &node) const
    {
        return this->val > node.val;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}