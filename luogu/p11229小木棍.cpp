#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> vec;
        int cnt = 0;
        if (n == 1)
        {
            cout << -1 << endl;
            continue;
        }

        while (n)
        {
            if (n >= 14)
            {
                vec.push_back(8);
                n -= 7;
            }
            if (n == 7)
            {
                vec.push_back(1);
                vec.push_back(5);
                n -= 7;
            }
            if (n >= 6)
            {
                if (vec.empty())
                    vec.push_back(6);
                else
                    cnt++;
                n -= 6;
            }
            if (n == 5)
            {
                vec.push_back(2);
                n -= 5;
            }
            if (n == 4)
            {
                vec.push_back(4);
                n -= 4;
            }
            if (n == 3)
            {
                vec.push_back(7);
                n -= 3;
            }
            if (n == 2)
            {
                vec.push_back(1);
                n -= 2;
            }
        }

        sort(vec.begin(), vec.end());

        cout << vec[0];
        for (int i = 0; i < cnt; i++) cout << 0;
        for (int i = 1; i < vec.size(); i++)
            cout << vec[i];
        cout << endl;
    }
    
    return 0;
}