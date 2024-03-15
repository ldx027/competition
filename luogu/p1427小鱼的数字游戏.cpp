#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<int> vec;
    while (x != 0)
    {
        vec.push_back(x);
        cin >> x;
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        cout << vec[i] << " ";
    }

    return 0;
}