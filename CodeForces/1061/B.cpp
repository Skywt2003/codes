#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=100005;


inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,m,ans=0;
int a[maxn];

bool cmp(int x,int y){return x>y;}

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    int ans=0;
    sort(a+1,a+1+n,cmp);
    int up=a[1]+1;
    for (int i=1;i<=n;i++){
        if (up==1) {ans+=a[i]-1;continue;}
        if (a[i]>=up) ans+=a[i]-up+1,a[i]=up-1;
        if (a[i]<up) ans-=up-a[i]-1;
        ans+=a[i]-1;up=a[i];
    }
    ans-=up-1;
    printf("%lld\n",ans);
    return 0;
}