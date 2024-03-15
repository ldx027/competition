#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
void print(int n)
{
    cout << n << "=" << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        cout << "+" << vec[i];
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int total = 0;
    vec.resize(n, 1);
    while (vec.size() > 1)
    {
        total++;
        print(n);
        vec[vec.size() - 2]++;
        vec[vec.size() - 1]--;
        if (vec[vec.size() - 1] < vec[vec.size() - 2])
        {
            vec[vec.size() - 2] += vec[vec.size() - 1];
            vec.pop_back();
        }
    }
    cout << total;

    return 0;
}
