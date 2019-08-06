#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2005,maxe=2000006;

int n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int f[maxn];
bool apr[maxn][maxn],egd[maxn][maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y; f[y]++;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

int a[maxn];

int level[maxn];
queue<int> que;

void Topology(){
    while (!que.empty()) que.pop();
    for (int i=1;i<=n;i++) if (f[i]==0) que.push(i),level[i]=1;
    while (!que.empty()){
        int head=que.front(); que.pop();
        for (int i=lnk[head];i;i=nxt[i]){
            level[to[i]]=max(level[to[i]],level[head]+1);
            f[to[i]]--;
            if (f[to[i]]==0) que.push(to[i]);
        }
    }
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read();
        for (int j=1;j<=x;j++) a[j]=read(),apr[i][a[j]]=true;
        for (int j=a[1];j<=a[x];j++) if (!apr[i][j])
            for (int k=1;k<=x;k++)
                if (!egd[j][a[k]]) add_edge(j,a[k]),egd[j][a[k]]=true;
    }
    Topology();
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,level[i]);
    printf("%lld\n",ans);
    return 0;
}