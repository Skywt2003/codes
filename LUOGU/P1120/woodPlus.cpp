#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=70;
int n,a[maxn],sum=0,maxx=0;
bool vis[maxn];
bool global_flag=true;

void DFS(int x,int now,int all){
    if (global_flag) return;
    if (now==all){
        global_flag=true;
        return;
    }
    for (int i=x-1;i>=1;i--) if (!vis[i] && now+a[i]<=all){
        vis[i]=true;
        DFS(i,now+a[i],all);
        if (global_flag) return;
        vis[i]=false;
    }
}

bool check(int x){
    memset(vis,0,sizeof(vis));
    for (int i=n;i>=1;i--) if (!vis[i]){
        global_flag=false;
        vis[i]=true;
        DFS(i,a[i],x);
        if (!global_flag) return false;
    }
    return true;
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();
        if (x>50) n--,i--; else a[i]=x,sum+=x,maxx=max(maxx,x);
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) printf("%lld ",a[i]); printf("\n");
    for (int i=maxx;i<=sum;i++) if (sum%i==0){
        if (check(i)){
            printf("%lld\n",i);
            return 0;
        }
    }
    return 0;
}
