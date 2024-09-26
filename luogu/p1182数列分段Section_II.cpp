#include <iostream>
#include <vector>
using namespace std;

#define wtf cout<<"wtf"<<endl

vector<int> vec;

int bin(int L, int R, int M)
{
    // cout << L << " " << R << endl;
    if (L == R)
        return L;

    int mid = L + ((R - L) >> 1);
    
    int cnt = 0, cur = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if ((cur += vec[i]) > mid)
        {
            if (++cnt > M - 1)
                break;
            cur = vec[i];
        }
    }

    if (cnt > M - 1)
        return bin(mid + 1, R, M);
    else
        return bin(L, mid, M);
}

int main()
{
    int N, M;
    cin >> N >> M;

    vec.resize(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    int Max = vec[0], sum = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        Max = max(Max, vec[i]);
        sum += vec[i];
    }


    cout << bin(Max, sum, M);

    return 0;
}