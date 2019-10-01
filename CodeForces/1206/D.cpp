#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;
const int maxe=205;
const int INF=0x3f3f3f3f3f3f3f3f;

int n;
int a[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int ans=INF;

map<int,bool> con[maxn];

void add_edge(int x,int y){
    tot++; to[tot]=y;
    nxt[tot]=lnk[x]; lnk[x]=tot;
}

int dist[maxn];

queue<int> que;
bool vis[maxn];
bool canuse[maxe];

void BFS(int s){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while (!que.empty()) que.pop();

    dist[s]=0; vis[s]=true; que.push(s);
    while (!que.empty()){
        int head=que.front(); que.pop();
        for (int i=lnk[head];i;i=nxt[i]) if (dist[head]+1<dist[to[i]] && canuse[i]){
            dist[to[i]]=dist[head]+1;
            if (!vis[to[i]]) vis[to[i]]=true,que.push(to[i]);
        }
    }
}

struct edge{
    int x,y,id;
};
edge b[maxe];
int bn=0;

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();

    for (int j=0;j<63;j++){
        int cnt=0,x1=-1,x2=-1;
        for (int i=1;i<=n;i++) if (a[i]&((int)1<<j)){
            cnt++;
            if (x1==-1) x1=i; else x2=i;
        }
        if (cnt>2){
            printf("3\n");
            return 0;
        } else if (cnt==2){
            if (con[x1][x2]||con[x2][x1]) continue;
            add_edge(x1,x2),add_edge(x2,x1);
            con[x1][x2]=true,con[x2][x1]=true;
            b[++bn]=(edge){x1,x2,tot-1};
        }
    }

    memset(canuse,true,sizeof(canuse));
    for (int i=1;i<=bn;i++){
        canuse[b[i].id]=canuse[b[i].id+1]=false;
        BFS(b[i].x);
        ans=min(ans,dist[b[i].y]+1);
        canuse[b[i].id]=canuse[b[i].id+1]=true;
    }

    printf("%lld\n",(ans==INF)?-1:ans);
    return 0;
}