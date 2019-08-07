// tarjan suo1 vertex
// 190801 from XCdev1216t3
// 190807 Updated

#include<bits/stdc++.h>
using namespace std;

// Fake arrays 为了不让 intelliSense 给我一大堆红红的下划线……
int lnk[0],nxt[0],to[0],vis[0],dfn[0],low[0],cnt,blt[0];
vector<int> inc[0];
stack<int> stk;

void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    stk.push(x); vis[x]=true;
    for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
        tarjan(to[i]);
        low[x]=min(low[x],low[to[i]]);
    } else if (vis[to[i]]) low[x]=min(low[x],low[to[i]]);

    if (dfn[x]==low[x]){
        for (;;){
            int now=stk.top(); stk.pop();
            vis[now]=false;
            blt[now]=x; inc[x].push_back(now);
            if (now==x) break;
        }
    }
}