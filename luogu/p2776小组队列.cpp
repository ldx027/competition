#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int T;
    cin >> T;


    string cmd;
    int x;
    while (T--)
    {
        cin >> cmd;
        if (cmd == "psuh")
        {
            cin >> x;
        }
        else if (cmd == "pop")
        {

        }
    }

    return 0;
}