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

int n,k;
int a[maxn];
int lft,rght;

signed main(){
    n=read(); k=read(); lft=1,rght=n;
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    while (lft+1<=n && a[lft+1] == a[lft]) lft++;
    while (rght-1>=1 && a[rght-1]==a[rght]) rght--;

    while (lft < rght){
        int now1=(a[lft+1]-a[lft])*lft;
        int now2=(a[rght]-a[rght-1])*(n-rght+1);
        if (now1<=now2 && now1<=k){
            k-=now1;lft++;
            while (lft+1<=n && a[lft+1] == a[lft]) lft++;
        } else if (now1>=now2 && now2<=k){
            k-=now2; rght--;
            while (rght-1>=1 && a[rght-1]==a[rght]) rght--;
        } else break;
    }
    // printf("%lld %lld\n",lft,rght);
    int delta=max(k/lft,k/(n-rght+1));
    if (lft>=rght) printf("0\n"); else printf("%lld\n",a[rght]-a[lft]-delta);
    return 0;
}