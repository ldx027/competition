#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<char>> vec(10, vector<char>(10));

struct Node
{
    int x, y, turn;

    Node(int _x = 0, int _y = 0) : x(_x), y(_y) { turn = 0; }

    void move()
    {
        if (x + dx[turn] >= 10 || x + dx[turn] < 0 || y + dy[turn] >= 10 || y + dy[turn] < 0)
            turn = (turn + 1) % 4;
        else if (vec[x + dx[turn]][y + dy[turn]] == '*')
            turn = (turn + 1) % 4;
        else
            x += dx[turn], y += dy[turn];
    }
};

int zip(Node &a, Node &b)
{
    return a.x * 1e5 + a.y * 1e4 + a.turn * 1e3 + b.x * 1e2 + b.y * 1e1 + b.turn;
}

unordered_set<int> st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node cow, person;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 'C') cow = Node(i, j);
            if (vec[i][j] == 'F') person = Node(i, j);
        }
    }

    int cnt = 0;
    while (1)
    {
        // cout << zip(person, cow) << endl;
        if (cow.x == person.x && cow.y == person.y) break;
        if (st.count(zip(person, cow)))
        {
            cnt = 0;
            break;
        }
        st.insert(zip(person, cow));

        cow.move();
        person.move();

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}