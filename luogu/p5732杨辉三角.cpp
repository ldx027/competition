#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vec(n + 1, 0);
    vector<int> vec2(n + 1, 0);
    vec[1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (vec2[j] = vec[j] + vec[j - 1]) << " ";
        }
        vec = vec2;
        cout << endl;
    }

    return 0;
}