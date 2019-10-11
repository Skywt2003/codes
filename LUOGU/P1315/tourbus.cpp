#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005,maxm=10005,maxk=100005;

int n,m,k;
int dist[maxn];
int in[maxn],out[maxn];
int down[maxn],sum[maxn];
int ans=0;

struct tourist{
    int t,x,y;
};
tourist a[maxm];

signed main(){
    n=read(); m=read(); k=read();
    for (int i=1;i<n;i++) dist[i]=read();
    for (int i=1;i<=m;i++) a[i].t=read(),a[i].x=read(),a[i].y=read(),down[a[i].y]++;

    for (int i=1;i<=m;i++) out[a[i].x]=max(out[a[i].x],a[i].t);
    for (int i=2;i<=n;i++) out[i]=max(out[i],out[i-1]),in[i]=max(in[i-1],out[i-1])+dist[i-1];

    pair<int,int> now;
    while (k--){
        now=make_pair(-1,-1);
        for (int i=n;i>1;i--){
            sum[i]=((in[i]>out[i])?sum[i+1]:0)+down[i];
            if (dist[i-1]>0 && sum[i]>now.first) now=make_pair(sum[i],i);
        }
        if (now.second == -1) break;
        in[now.second]--; dist[now.second-1]--;
        for (int i=now.second+1;i<=n;i++) in[i]=max(in[i-1],out[i-1])+dist[i-1];
    }
    
    for (int i=1;i<=m;i++) ans+=in[a[i].y]-a[i].t;
    printf("%lld\n",ans);
    return 0;
}