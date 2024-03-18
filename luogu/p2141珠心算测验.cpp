#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<int> st;

    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        st.insert(x);
    }

    int cnt = 0;
    for (auto it1 = st.begin(); it1 != st.end(); it1++)
    {
        for (auto it2 = it1; it2 != st.end(); it2++)
        {
            
            cnt += st.count(*it1 + *it2);
        }
    }

    cout << cnt << endl;

    return 0;
}