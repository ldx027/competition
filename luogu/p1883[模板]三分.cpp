#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<vector<int>> vec(n, vector<int>(3)); 
        for (int i = 0; i < n; i++)
            cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
}