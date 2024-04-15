#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec(10, 0);

    int M, N;
    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        string num = to_string(i);
        for (int j = 0; j < num.size(); j++) vec[num[j] - '0']++;
    }

    for (int i = 0; i < 10; i++) cout << vec[i] << " ";

    return 0;
}