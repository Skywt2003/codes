#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

const int maxn=200005;

int n,m,l[maxn],r[maxn];
int f[maxn];

int head=1,tail=1;
pair<int,int> que[maxn];

signed main(){
    n=read(); m=read();
    for (int i=1;i<=n+1;i++) r[i]=i-1;
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        r[y]=min(r[y],x-1); l[y+1]=max(l[y+1],x);
    }
    for (int i=2;i<=n+1;i++) l[i]=max(l[i],l[i-1]);
    for (int i=n;i>=1;i--) r[i]=min(r[i],r[i+1]);

    memset(f,-1,sizeof(f));

    que[head]=make_pair(0,0);
    for (int i=1;i<=n+1;i++){
        while ((head<=tail&&que[head].second < l[i]) || (head+1<=tail&&que[head+1].second<=r[i]&&que[head+1].first>=que[head].first)) head++;
        if (head<=tail && que[head].second <= r[i]){
            f[i]=que[head].first+(i!=n+1);
        }
        if (f[i]!=-1) que[++tail]=make_pair(f[i],i);
    }
    printf("%lld\n",f[n+1]);
    return 0;
}