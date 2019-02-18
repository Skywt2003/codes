#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>
 
using namespace std;
 
#define LL long long
const int INF = 0x3f3f3f3f;
 
int n, q, x, y, p;
int top[200009], g[200009], G[200009], G1[200009];
int s[200009], nt[400009], e[400009], l[400009], cnt;
int ct[200009], mx[200009], fa[200009], dep[200009];
LL a[200009], f[200009 * 4],z;
 
void dfs(int k, int f)
{
	dep[k] = dep[f] + 1;
	fa[k] = f, ct[k] = 1, mx[k] = 0;
	for (int i = s[k]; ~i; i = nt[i])
	{
		if (e[i] == f) continue;
		dfs(e[i], k);
		ct[k] += ct[e[i]];
		if (ct[e[i]] > ct[mx[k]]) mx[k] = e[i];
	}
}
 
void Dfs(int k, int t)
{
	top[k] = !t ? k : top[fa[k]];
	g[k] = ++cnt;
	if (mx[k]) Dfs(mx[k], 1);
	for (int i = s[k]; ~i; i = nt[i])
	{
		if (e[i] == fa[k]) continue;
		if (e[i] == mx[k]) { G[l[i]] = g[e[i]]; G1[g[e[i]]] = l[i]; continue; }
		Dfs(e[i], 0);
		G[l[i]] = g[e[i]];
		G1[g[e[i]]] = l[i];
	}
}
 
LL mul(LL x, LL y)
{
	return 1.0*x*y > 1e18 ? 0 : x*y;
}
 
void build(int k, int l, int r)
{
	if (l == r) { f[k] = a[G1[l]]; return; }
	int mid = (l + r) >> 1;
	build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	f[k] = mul(f[k << 1], f[k << 1 | 1]);
}
 
void update(int k, int l, int r, int p, LL val)
{
	if (l == r) { f[k] = val; return; }
	int mid = (l + r) >> 1;
	if (p <= mid) update(k << 1, l, mid, p, val);
	else update(k << 1 | 1, mid + 1, r, p, val);
	f[k] = mul(f[k << 1], f[k << 1 | 1]);
}
 
LL query(int k, int l, int r, int ll, int rr)
{
	if (l >= ll&&r <= rr) return f[k];
	int mid = (l + r) >> 1;
	LL ans = 1;
	if(ll<=mid) ans= mul(ans, query(k<<1,l,mid,ll,rr));
	if (rr > mid) ans = mul(ans, query(k << 1 | 1, mid + 1, r, ll, rr));
	return ans;
}
 
void solve(int x, int y, LL z)
{
	LL ans = 1;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans=mul(ans,query(1, 1, n, g[top[x]], g[x])); x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans = mul(ans, query(1, 1, n, g[x] + 1, g[y]));
	printf("%lld\n", ans ? z / ans : ans);
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (~scanf("%d%d", &n, &q))
	{
		memset(s, -1, sizeof s);
		dep[0] = ct[0] = cnt = 0;
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d%lld", &x, &y, &a[i]);
			nt[cnt] = s[x], s[x] = cnt, l[cnt] = i, e[cnt++] = y;
			nt[cnt] = s[y], s[y] = cnt, l[cnt] = i, e[cnt++] = x;
		}
		dfs(1, 0);
		Dfs(1, cnt = 0);
		build(1, 1, n);
		while (q--)
		{
			scanf("%d", &p);
			if (p == 2)
			{
				scanf("%d%lld", &x, &z);
				update(1, 1, n, G[x], z);
			}
			else
			{
				scanf("%d%d%lld", &x, &y, &z);
				if (x == y) { printf("%lld\n", z); continue; }
				solve(x, y, z);
			}
		}
	}
	return 0;
}
