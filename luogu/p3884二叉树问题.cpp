#include <iostream>
#include <vector>
using namespace std;

#define ll long long

struct Node
{
    ll parent = 0;
    int tier = 1;
};

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int next;
};

int Edge::cnt = 1;
vector<int> Edge::head;
vector<Edge> edges;

vector<Node> tree;
vector<ll> width;
ll height = 0;

void addEdge(int u, int v)
{

}