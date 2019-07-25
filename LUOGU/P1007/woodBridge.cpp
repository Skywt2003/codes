#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=5005;

int L,n;
int a[maxn];

signed main(){
    L=read();n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
        if (a[i]>L || a[i]<1) i--,n--;
    }
    if (n==0){
        printf("0 0\n");
        return 0;
    }
    sort(a+1,a+1+n);
    int ans1=0,ans2=max(a[n]-0,L+1-a[1]);
    for (int i=1;i<=n;i++) ans1=max(ans1,min(a[i]-0,L+1-a[i]));
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}
