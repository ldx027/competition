#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define AA 17

struct Soldier { int id, l, r; };
bool cmp(Soldier a, Soldier b) { return a.l < b.l; }

int n, m;
Soldier vec[400005];
int st[400005][20];
int ans[200005];

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

int main()
{
    n = read(), m = read();

    for (int i = 1; i <= n; i++)
    {
        vec[i].l = read(), vec[i].r = read();
        if (vec[i].r < vec[i].l)
            vec[i].r += m;
        vec[i].id = i;
    }
    sort(vec + 1, vec + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        vec[i + n].l = vec[i].l + m;
        vec[i + n].r = vec[i].r + m;
        vec[i + n].id = vec[i].id;
    }

    for (int i = 1; i <= (n << 1); i++)
    {
        int tmp = i;
        while (tmp <= (n << 1) && vec[tmp].l <= vec[i].r)
            tmp++;
        st[i][0] = tmp - 1;
    }

    for (int i = 1; i < AA; i++)
        for (int j = 1; j <= (n << 1); j++)
            st[j][i] = st[st[j][i - 1]][i - 1];

    for (int i = 1; i <= n; i++)
    {
        int lmt = vec[i].l + m;
        int cur = i;

        for (int j = AA - 1; j >= 0; j--)
        {
            if (st[cur][j] != 0 && vec[st[cur][j]].r < lmt)
            {
                ans[vec[i].id] += (1 << j);
                cur = st[cur][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i] + 2);

    return 0;
}