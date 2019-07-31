#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;
int m,n,ans=0;
int sum_c[maxn],sum_l[maxn];

signed main(){
    m=read();n=read(); swap(n,m);
    int x1,y1,x2,y2;
    while (~scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2)){
        if (x1>x2) swap(x1,x2); if (y1>y2) swap(y1,y2);
        if (x2==x1+1) sum_c[y2]++; else
        if (y2==y1+1) sum_l[y2]++;
    }
    
    ans=n-1-sum_c[1];
    for (int i=2;i<=m;i++){
        ans+=n-1-sum_c[i];
        if (sum_l[i]==0) ans+=2; else ans-=sum_l[i]-1;
    }
    printf("%lld\n",ans);
    return 0;
}