// A game

#include <bits/stdc++.h>

using namespace std;
//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;
const int maxn=35;

int T,n,a[maxn];
int ans=INF;

bool vis[2][maxn];
bool prt;

int myabs(int x){
    return (x>0)?x:-x;
}

void DFS(int step,set<int> s){
    if (ans==0) return;
    if (step==n-1){
        ans=min(ans,(*(s.begin())));
        return;
    }
    set<int> now,nxt;
    set<int>::iterator i,j;
    for (i=s.begin();i!=s.end();i++)
        for (j=s.begin();j!=s.end();j++) if (i!=j){
            int x=(*i)+(*j),y=myabs((*i)-(*j)),z=(*i)*(*j);
            now=s; now.erase(now.find(*i)); now.erase(now.find(*j));
            if (now.count(x) || now.count(y) || now.count(z)){ans=0;return;}
            nxt=now; nxt.insert(x); DFS(step+1,nxt);
            nxt=now; nxt.insert(y); DFS(step+1,nxt);
            nxt=now; nxt.insert(z); DFS(step+1,nxt);
        }
}

signed main(){
    T=read();
    while (T--){
        memset(vis,0,sizeof(vis)); prt=false; ans=INF;
        n=read();
        if (n>30) {printf("0\n");for (int i=1;i<=n;i++) read();continue;}
        for (int i=1;i<=n;i++) a[i]=read();
        if (n==0) {printf("0\n");continue;}
        if (n==1) {printf("%d\n",a[1]);continue;}
        sort(a+1,a+1+n);
        for (int i=1;i<=n;i++){
            for (int j=0;j<=30;j++) vis[i&1][j]=vis[i&1^1][j];
            if (vis[i&1][0]||vis[i&1][a[i]]){printf("0\n"); prt=true; break;}
            for (int j=1;j<=30;j++) if (vis[i&1^1][j]){
                if (a[i]+j<=30) vis[i&1][a[i]+j]=true;
                vis[i&1][myabs(a[i]-j)]=true;
                if (a[i]*j<=30) vis[i&1][a[i]*j]=true;
            }
            vis[i&1][a[i]]=true;
        }
        if (prt) continue;
        set<int> s; s.clear();
        for (int i=1;i<=n;i++) s.insert(a[i]);
        DFS(0,s);
        printf("%d\n",ans);
    }
    return 0;
}
