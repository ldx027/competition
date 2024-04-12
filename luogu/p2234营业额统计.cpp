#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int x;
    scanf("%d", &N);
    set<long long> st;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (st.empty())
            ans += x;
        else
        {
            auto it = st.lower_bound(x);
            auto it2 = (it == st.begin() ? it : it--);
            ans += min(abs(*it - x), abs(*it2 - x));
        }
        st.insert(x);
    }

    printf("%d\n", ans);
    return 0;
}