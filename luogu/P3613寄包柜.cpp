#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n, q;
    int cmd, x, y, k;
    cin >> n >> q;
    unordered_map<int, unordered_map<int, int>> box;

    for (int i = 0; i < q; i++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> x >> y >> k;
            box[x][y] = k;
        }
        else if (cmd == 2)
        {
            cin >> x >> y;
            cout << box[x][y] << endl;
        }
    }

    return 0;
}