#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int attack(int state, int ele, int hurt, int k)
{
    if (state == 0) return hurt;
    if (state == ele) return hurt;
    if (ele == 1) return hurt + k;
    return 2 * hurt;
}

int hurt(vector<int> fire, vector<int> ice, int state, int idxf, int idxi, int k)
{
    cout << idxf << " " << idxi << endl;
    if (idxf >= fire.size()) return 0;
    if (idxi >= ice.size()) return 0;
    int hurtf = hurt(fire, ice, (state == 0 ? 1 : 0), idxf + 1, idxi, k) + attack(state, 1, fire[idxf + 1], k);
    int hurti = hurt(fire, ice, (state == 0 ? 2 : 0), idxf, idxi + 1, k) + attack(state, 2, ice[idxi + 1], k);
    cout << "hurtf" << hurtf << endl << "hurti" << hurti << endl;
    return max(hurtf, hurti);
}

int main()
{
    ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    int x;
    vector<int> fire;
    vector<int> ice;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        fire.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        ice.push_back(x);
    }
    sort(fire.begin(), fire.end());
    sort(ice.begin(), ice.end());

    cout << hurt(fire, ice, 0, -1, -1, k) << endl;

    return 0;
}