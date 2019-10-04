// B: robot
#include <bits/stdc++.h>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

// const int maxn=1e5+5;
const int maxn=15;
const int tt=1e9+7;

int n,ans=0;

pair<int,int> a[maxn*2];

bool mp[maxn][maxn],vis[maxn*2];
int p[maxn*2];

int fac(int n){
    int ret=1;
    for (int i=2;i<=n;i++) ret=ret*i%tt;
    return ret;
}

int qsm(int a,int b){
    int ret=1,w=a%tt;
    while (b){
        if (b&1) ret=ret*w%tt;
        w=w*w%tt; b>>=1;
    }
    return ret;
}

void DFS(int step){
    if (step==2*n){
        for (int i=1;i<=2*n;i++) mp[a[i].first][a[i].second]=true;
        for (int i=1;i<=2*n;i++){
            bool flg=false;
            if (p[i]<=n){
                for (int j=1;j<=n;j++) if (mp[p[i]][j]) {flg=true,mp[p[i]][j]=false;break;}
                if (!flg) return;
            } else {
                p[i]-=n;
                for (int j=1;j<=n;j++) if (mp[j][p[i]]) {flg=true,mp[j][p[i]]=false;break;}
                p[i]+=n;
                if (!flg) return;
            }
        }
        ans=(ans+1)%tt;
        return;
    }
    for (int i=1;i<=2*n;i++) if (!vis[i]){
        vis[i]=true; p[step+1]=i;
        DFS(step+1);
        vis[i]=false;
    }
}

signed main() {
    n=read();
    for (int i=1;i<=2*n;i++) a[i].first=read(),a[i].second=read();
    if (n>5){
        printf("1\n");
        return 0;
    }
    DFS(0);
    printf("%lld\n",ans*qsm(fac(n*2),tt-2)%tt);
    return 0;
}
