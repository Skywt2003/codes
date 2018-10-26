#include <bits/stdc++.h>
using namespace std;
 
const int N = 150;
 
int ans, n, Ecnt, a[N], b[N], vis[N], M[N][N];
vector<int> g;
 
bool cmp(int a, int c) {
    return b[a] > b[c];
}
inline void add(int u, int v) {
    M[u][v] = 1;
}
void dfs(int u) {
    ans ++; vis[u] = 1;
    for(int i = 1; i <= n; i++)
        if(M[u][i] && !vis[i]) {
            dfs(i);
        }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        b[i] = n - 1 - a[i];
    }
    for(int i_ = 1; i_ <= n; i_++) {
        int i = -1,minn = 150;
        for(int j = 1; j <= n; j++)
            if(a[j] < minn) i = j, minn = a[j];
        for(int j = 1; j <= a[i]; j++) {
            g.clear();
            for(int k = 1; k <= n; k++)
                if((i != k) && (!M[k][i]) && (!M[i][k])) g.push_back(k);
            sort(g.begin(), g.end(), cmp);
            //assert((int)g.size() > 0);
            b[g[0]] --;
            add(i, g[0]);
        }
        for(int j = 1; j <= n; j++) {
        	if(!M[i][j] && i != j)
        		add(j, i), a[j] --;
        }
        a[i] = 150;
    }
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        dfs(i);
    }
    printf("%d\n", ans);
    return 0;
}
