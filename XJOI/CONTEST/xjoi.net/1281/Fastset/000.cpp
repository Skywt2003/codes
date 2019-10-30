#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

const ll N = 300010;
ll n, ans;
ll ver[N<<1], Next[N<<1], head[N], tot;

inline ll read() {
    ll x = 0, tmp = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') tmp = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = (x<<3)+(x<<1)+(ch^48);
        ch = getchar();
    }
    return tmp*x;
}

inline void addEdge(ll x, ll y) {
    ver[++tot] = y;
    Next[tot] = head[x];
    head[x] = tot;
}

namespace lowest_command_auto {
    ll d[N] = {
        0
    }, p[N][21] = {
        0
    };
    void dfs(ll x, ll before) {
        d[x] = d[before]+1;
        p[x][0] = before; for(ll i = 1; i <= 20; i++) p[x][i] = p[p[x][i-1]][i-1];
        for(ll i = head[x]; i; i = Next[i]) {
            ll y = ver[i];
            if(y == before) continue;
            dfs(y, x);
        }
    }
    inline ll LCA(ll x, ll y) {
        if(d[x] > d[y]) swap(x, y);
        for(ll i = 20; i >= 0; i--) {
            if(d[x]+(1<<i) <= d[y]) y = p[y][i];
        }
        if(x != y) {
            for(ll i = 20; i >= 0; i--) {
                if(p[x][i] != p[y][i]) {
                    x = p[x][i];
                    y = p[y][i];
                }
            }
            return p[x][0];
        }
        return x;
    }
    inline ll dis(ll x, ll y) {
        ll rt = LCA(x, y);
        return d[x]+d[y]-2*d[rt];
    }
}

namespace Segment {
    struct SegmentTree {
        ll l, r, val;
    }
    tree[N<<2];
    inline void pushdown(ll p) {
        if(tree[p].val) {
            tree[p<<1].val = tree[p<<1|1].val = tree[p].val;
            tree[p].val = 0;
        }
    }
    void build(ll p, ll l, ll r) {
        tree[p].l = l; tree[p].r = r;
        if(l == r) {
            tree[p].val = l;
            return;
        }
        ll mid = (l+r)>>1;
        build(p<<1, l, mid);
        build(p<<1|1, mid+1, r);
    }
    void update(ll p, ll l, ll r, ll x) {
        if(l <= tree[p].l && tree[p].r <= r) {
            tree[p].val = x;
            return;
        }
        pushdown(p);
        ll mid = (tree[p].l+tree[p].r)>>1;
        if(l <= mid) update(p<<1, l, r, x);
        if(r > mid) update(p<<1|1, l, r, x);
    }
    ll query(ll p, ll l, ll r, ll x) {
        if(tree[p].val) return lowest_command_auto::dis(tree[p].val, x)*(min(r, tree[p].r)-max(l, tree[p].l)+1);
        pushdown(p);
        ll mid = (tree[p].l+tree[p].r)>>1, ans = 0;
        if(l <= mid) ans += query(p<<1, l, r, x);
        if(r > mid) ans += query(p<<1|1, l, r, x);
        return ans;
    }
}

int main() {
    n = read();
    for(ll i = 1; i < n; i++) {
        ll x = read(), y = read();
        addEdge(x, y);
        addEdge(y, x);
    }
    lowest_command_auto::dfs(1, 0);
    Segment::build(1, 1, n);
    while(n--) {
        ll l = read(), r = read(), x = read();
        ans += Segment::query(1, l, r, x);
        Segment::update(1, l, r, x);
    }
    cout<<ans<<endl;
    return 0;
}