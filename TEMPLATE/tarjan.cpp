// tarjan suo1 vertex
// 190801 from XCdev1216t3

void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    stk[++stk_top]=x; vis[x]=true;
    for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
        tarjan(to[i]);
        low[x]=min(low[x],low[to[i]]);
    } else if (vis[to[i]]) low[x]=min(low[x],low[to[i]]);

    if (dfn[x]==low[x]){
        for (;;){
            int now=stk[stk_top]; stk_top--;
            blt[now]=x; vis[now]=false;
            inc[x].push_back(now);
            if (now==x) break;
        }
    }
}