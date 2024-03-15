#include <iostream>
using namespace std;

bool is1(int x)
{
    return !(x % 2);
}


bool is2(int x)
{
    return x > 4 && x <= 12;
}

int main()
{
    int x;
    cin >> x;
    bool ans[4] = {is1(x) && is2(x), 
        is1(x) || is2(x), 
        (is1(x) || is2(x)) && !(is1(x) && is2(x)),
        !is1(x) && !is2(x)};

    for (int i = 0; i < 4; i++) cout << (ans[i] ? 1 : 0) << " ";

    return 0;
}