#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int idx, h, min;
    char cmd;
    string time;

    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < N; i++)
    {
        int n = 0;
        int sum = 0;
        while (1)
        {
            scanf("%d %c %d:%d", &idx, &cmd, &h, &min);

            if (idx == 0)
            {
                break;
            }

            if (cmd == 'S')
            {
                if (mp.count(idx))
                    continue;
                else
                {
                    mp.insert({idx, {h, min}});
                }
            }

            else if (cmd == 'E')
            {
                if (!mp.count(idx))
                    continue;
                else
                {
                    n++;
                    sum += (h - mp[idx].first) * 60 + min - mp[idx].second;
                    mp.erase(idx);
                }
            }
        }
        if (n > 0)
            cout << n << " " << int(double(sum) / n + 0.5) << endl;
        else
            cout << "0 0\n";
    }
}