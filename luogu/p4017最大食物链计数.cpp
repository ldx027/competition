#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define mod 80112002

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

int main()
{
    int n, m;
}