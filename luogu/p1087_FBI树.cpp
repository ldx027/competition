#include <iostream>
#include <vector>
using namespace std;

vector<char> vec;

void func(int idx = 1)
{
    // cout << idx << endl;
    if ((idx << 1) < vec.size())
    {
        func(idx << 1);
        func((idx << 1) + 1);
    }
    if (!vec[idx]) vec[idx] = vec[(idx << 1) + 1] == vec[idx << 1] ? vec[idx << 1] : 'F';
    cout << vec[idx];

}

int main()
{
    int N;
    cin >> N;

    vec.resize(1 << (N + 1), 0);

    char c;
    for (int i = 0; i < (1 << N); i++)
    {
        cin >> c;
        vec[(1 << N) + i] = (c == '1' ? 'I' : 'B');
    }

    // for (int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;

    func();

    return 0;
}
