#include <iostream>
#include <vector>
using namespace std;

bool huiwen(vector<int> vec)
{
    for (int i = 0; i < vec.size() / 2; i++)
    {
        if (vec[i] != vec[vec.size() - 1 - i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> vec;
    while (M)
    {
        vec.push_back(M % 10);
        M /= 10;
    }

    for (int i = 0; i <= 30; i++)
    {
        // for (int j = 0; j < vec.size(); j++) cout << vec[vec.size() - 1 - j];
        // cout << endl;
        if (huiwen(vec))
        {
            cout << "STEP=" << i << endl;
            return 0;
        }

        vector<int> temp = vec;
        for (int j = 0; j < vec.size(); j++) temp[j] += vec[vec.size() - 1 - j];
        vec = temp;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] >= N)
            {
                if (j == vec.size() - 1) vec.push_back(0);
                vec[j + 1] += vec[j] / N;
                vec[j] %= N;
            }
        }
    }

    cout << "Impossible!" << endl;

    return 0;
}