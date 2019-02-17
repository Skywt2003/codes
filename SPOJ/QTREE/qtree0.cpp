#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e4 + 10;
int firste[N], nexte[N << 1], v[N << 1], w[N << 1];
int fa[N], d[N], sz[N], son[N];
int id[N], top[N], up[N], down[N];
int mx[N << 2];
char s[20];
int t, n, e, cnt;
void build(int x, int y, int z)
{
    nexte[++e] = firste[x];
    firste[x] = e;
    v[e] = y;
    w[e] = z;
}
void dfs1(int u)
{
    sz[u] = 1;
    for(int p = firste[u]; p; p = nexte[p])
        if(v[p] != fa[u])
        {
            fa[v[p]] = u;
            d[v[p]] = d[u] + 1;
            down[p >> 1] = v[p];
            dfs1(v[p]);
            sz[u] += sz[v[p]];
            if(sz[v[p]] > sz[son[u]])
                son[u] = v[p];
        }
}
void dfs2(int u)
{
    id[u] = ++cnt;
    if(son[u])
    {
        top[son[u]] = top[u];
        dfs2(son[u]);
    }
    for(int p = firste[u]; p; p = nexte[p])
        if(v[p] != fa[u] && v[p] != son[u])
        {
            top[v[p]] = v[p];
            dfs2(v[p]);
        }
}
void update(int x, int L, int R, int tl, int tr, int y)
{
    if(L == tl && tr == R)
    {
        mx[x] = y;
        return;
    }
    int mid = (tl + tr) >> 1;
    if(L < mid)
        update(x << 1, L, R, tl, mid, y);
    else
        update(x << 1 | 1, L, R, mid, tr, y);
    mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
int query(int x, int L, int R, int tl, int tr)
{
    if(L == R)
        return 0;
    if(L <= tl && tr <= R)
        return mx[x];
    int mid = (tl + tr) >> 1, re = 0;
    if(L < mid)
        re = max(re, query(x << 1, L, R, tl, mid));
    if(mid < R)
        re = max(re, query(x << 1 | 1, L, R, mid, tr));
    return re;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        e = 1;
        memset(firste, 0, sizeof firste);
        memset(fa, 0, sizeof fa);
        memset(d, 0, sizeof d);
        memset(sz, 0, sizeof sz);
        memset(son, 0, sizeof son);
        memset(id, 0, sizeof id);
        memset(top, 0, sizeof top);
        memset(up, 0, sizeof up);
        memset(down, 0, sizeof down);
        memset(mx, 0, sizeof mx);
        cnt = 0;
        top[1] = 1;
        scanf("%d", &n);
        int x, y, z;
        for(int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &x, &y, &z);
            build(x, y, z);
            build(y, x, z);
        }
        dfs1(1);
        dfs2(1);
        for(int i = 2; i < (n << 1); i += 2)
        {
            int l = id[v[i]], r = id[v[i ^ 1]];
            if(l > r)
                swap(l, r);
            if(r - l == 1)
                update(1, l, r, 1, cnt, w[i]);
            else
            {
                if(id[v[i]] > id[v[i ^ 1]])
                    up[v[i]] = w[i];
                else
                    up[v[i ^ 1]] = w[i];
            }
        }
        while(scanf("%s", s), s[0] != 'D')
        {
            if(s[0] == 'Q')
            {
                int ans = 0, x, y;
                scanf("%d%d", &x, &y);
                while(top[x] != top[y])
                {
                    if(d[top[x]] < d[top[y]])
                        swap(x, y);
                    ans = max(ans, query(1, id[top[x]], id[x], 1, cnt));
                    x = top[x];
                    ans = max(ans, up[x]);
                    x = fa[x];
                }
                if(d[x] < d[y])
                    swap(x, y);
                ans = max(ans, query(1, id[y], id[x], 1, cnt));
                printf("%d\n", ans);
            }
            else
            {
                int x, y;
                scanf("%d%d", &x, &y);
                x = down[x];
                if(top[x] != x)
                    update(1, id[fa[x]], id[x], 1, cnt, y);
                else
                    up[x] = y;
            }
        }
    }
    return 0;
}