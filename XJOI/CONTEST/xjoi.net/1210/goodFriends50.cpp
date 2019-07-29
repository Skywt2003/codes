#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;
int n;
bool sat[maxn];

struct edge{
    int x,y,w;
};
edge a[maxn];

#define mid ((L+R)/2)
int ans=-1e9-1;

bool DFS(int now,int cnt,int tot,int x){
    if (cnt==n/2 && tot==n) return true;
    if (cnt>n/2) return false;
    if (now==n) return false;
    for (int i=now+1;i<=n;i++) if (a[i].w>=x && (!sat[a[i].x]) && (!sat[a[i].y])){
        sat[a[i].x]=sat[a[i].y]=true;
        if (DFS(i,cnt+1,tot+2,x)) return true;
        sat[a[i].x]=sat[a[i].y]=false;
    }
    return false;
}

signed main(){
    n=read();
    if (n&1){
        printf("no answer\n");
        return 0;
    }
    for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].w=read();
    int L=-1e9,R=1e9;
    while (L<=R){
        memset(sat,0,sizeof(sat));
        if (DFS(0,0,0,mid)) ans=mid,L=mid+1; else R=mid-1;
    }
    if (ans==-1e9-1) printf("no answer\n"); else printf("%lld\n",ans);
    return 0;
}