#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    int ans = 0;
    for (int i = 0, j = 0; i < S.size() && j < T.size(); i++)
        if (S[i] == T[j])
        {
            j++;
            ans++;
        }

    cout << ans << endl;
    return 0;
}