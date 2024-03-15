#include <iostream>
using namespace std;

int main()
{
    int apple[10];
    for (int i = 0; i < 10; i++) cin >> apple[i];
    int L, ans = 0;
    cin >> L;
    for (int i = 0; i < 10; i++)
        if (L + 30 >= apple[i])
            ans++;
    cout << ans;


    return 0;
}