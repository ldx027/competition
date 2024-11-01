#include <iostream>
#include <unordered_set>
using namespace std;

int card(char a, char b)
{
    int base;
    switch (a)
    {
    case 'D':
        base = 0;
        break;
    case 'C':
        base = 13;
        break;
    case 'H':
        base = 26;
        break;
    case 'S':
        base = 39;
        break;
    }

    int c;
    switch (b)
    {
    case 'A':
        c = 1;
        break;
    case 'T':
        c = 10;
        break;
    case 'J':
        c = 11;
        break;
    case 'Q':
        c = 12;
        break;
    case 'K':
        c = 13;
        break;
    default:
        c = b - '0';
        break;
    }

    return base + c;
}

int main()
{
    int n;
    cin >> n;

    unordered_set<int> st;
    for (int i = 1; i <= 52; i++)
        st.insert(i);
    
    char u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        st.erase(card(u, v));
    }

    cout << st.size() << endl;

    return 0;
}