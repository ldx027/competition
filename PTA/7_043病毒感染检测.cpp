#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    string a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        bool cmd = false;
        for (int j = 0; j < a.size(); j++)
        {
            a.push_back(a[0]);
            a.erase(a.begin());
            if (b.find(a) != string::npos)
            {
                cmd = true;
                break;
            }
        }
        cout << (cmd ? "YES" : "NO") << endl;
    }

    return 0;
}