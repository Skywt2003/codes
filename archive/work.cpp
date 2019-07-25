#include<bits/stdc++.h>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=504,maxe=1000005;
int n,m,e,INF=(int)1<<60;
int lnk[maxn][maxn];
int X[maxn],Y[maxn],match[maxn],slack[maxn];
bool S[maxn],T[maxn];

void update(){
    int d=INF;
    for (int i=1;i<=n;i++) if (!T[i]) d=min(d,slack[i]);
    for (int i=1;i<=n;i++){
        if (S[i]) X[i]-=d;
        if (T[i]) Y[i]+=d;
    }
}

bool Find(int x){
    S[x]=true;
    for (int y=1;y<=n;y++){
        if (T[y]) continue;
        if (X[x]+Y[y] == lnk[x][y]){
            T[y]=true;
            if (match[y]==-1 || Find(match[y])){
                match[y]=x;
                return true;
            }
        } else slack[y]=min(slack[y],X[x]+Y[y]-lnk[x][y]);
    }
    return false;
}

signed main(){
    // memset(lnk,0,sizeof(lnk));INF=lnk[0][0];
    n=read();m=read();e=read();
    n=m;
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        lnk[x][y]=z;
    }

    for (int i=1;i<=n;i++){
        X[i]=Y[i]=0;match[i]=-1;
        for (int j=1;j<=n;j++) X[i]=max(X[i],lnk[i][j]);
    }

    for (int i=1;i<=n;i++){
        memset(slack,63,sizeof(slack));
        for (;;){
            memset(S,0,sizeof(S)); memset(T,0,sizeof(T));
            if (!Find(i)) update(); else break;
        }
    }

    int ans=0;
    for (int i=1;i<=n;i++) ans+=lnk[match[i]][i];
    printf("%lld\n",ans);
    return 0;
}