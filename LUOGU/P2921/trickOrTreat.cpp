#include<bits/stdc++.h>
// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxe=100005*2;

int n;
int to[maxn],f[maxn];

int cnt=0;
int blt[maxn]; // Belongs to which loop
int size[maxn]; // The size of each loop
int ans[maxn];

queue<int> que;

void Topology(){
    while (!que.empty()) que.pop();
    for (int i=1;i<=n;i++) if (f[i]==0) que.push(i);
    while (!que.empty()){
        int head=que.front(); que.pop();
        f[to[head]]--;
        if (f[to[head]]==0) que.push(to[head]);
    }
}

bool vis[maxn];
vector<int> vec;

void DFS(int x,int id){
    vec.push_back(x);
    vis[x]=true; blt[x]=id; size[id]++;
    if (!vis[to[x]]) DFS(to[x],id);
}

void find_answer(int x){
    if (to[x]==x) {ans[x]=1;return;}
    if (!ans[to[x]]) find_answer(to[x]);
    ans[x]=ans[to[x]]+1;
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) to[i]=read(),f[to[i]]++;
    Topology();

    for (int i=1;i<=n;i++) if (f[i] && !vis[i]){
        vec.clear();
        DFS(i,++cnt);
        for (int j=0;j<vec.size();j++) ans[vec[j]]=size[cnt];
    }
    for (int i=1;i<=n;i++) if (!ans[i]) find_answer(i);

    for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}