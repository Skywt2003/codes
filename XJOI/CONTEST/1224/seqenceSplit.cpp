#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e5+5;
const int INF=(int)1<<60;
int n,k,a[maxn],sum[maxn];
int f[maxn],g[maxn];
int que[maxn],head=1,tail=1;

double sloop(int i,int j){
    if (sum[i]==sum[j]) return -INF;
    return (double)((g[i]-sum[i]*sum[i])-(g[j]-sum[j]*sum[j]))/(sum[j]-sum[i]);
}

signed main(){
    n=read(); k=read();
    for (int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=k;i++){
        head=tail=1;
        que[1]=0;
        for (int i=1;i<=n;i++){
            while (head<tail && sloop(que[head],que[head+1]) <= sum[i]) head++;
            f[i]=g[que[head]]+sum[que[head]]*(sum[i]-sum[que[head]]);
            while (head<tail && sloop(que[tail-1],que[tail]) >= sloop(que[tail],i)) tail--;
            que[++tail]=i;
        }
        memcpy(g,f,sizeof(f));
    }
    printf("%lld\n",f[n]);
    return 0;
}