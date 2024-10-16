#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Card
{
    int a, b;
};

vector<Card> cards;
vector<int> buff1, buff2;
vector<bool> vec;

int main()
{
    int n;
    cin >> n;

    cards.resize(n);
    buff1.resize(n);
    buff2.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cards[i].a >> cards[i].b;
        buff1[i] = cards[i].a;
        buff2[i] = cards[i].b;
    }

    sort(buff1.begin(), buff1.end());
    sort(buff2.begin(), buff2.end());
    buff1.erase(unique(buff1.begin(), buff1.end()), buff1.end());
    buff2.erase(unique(buff2.begin(), buff2.end()), buff2.end());

    for (int i = 0; i < n; i++)
    {
        cards[i].a = lower_bound(buff1.begin(), buff1.end(), cards[i].a) - buff1.begin();
        cards[i].b = lower_bound(buff2.begin(), buff2.end(), cards[i].b) - buff2.begin();
    }

    int kind = *buff2.rbegin() + 1;

    vec.resize(*buff1.rbegin() * (kind + 3) + 1, false);
    for (int i = 0; i < n; i++)
        vec[cards[i].a * (kind + 1) + cards[i].b] = true;
    
    int Max = 1;
    vector<int> dp(vec.size(), 1);
    for (int i = 1; i < dp.size(); i++)
        if (vec[i] && vec[i - 1])
            dp[i] += dp[i - 1], Max = max(Max, dp[i]);
    
    cout << n - Max << endl;

    return 0;
}