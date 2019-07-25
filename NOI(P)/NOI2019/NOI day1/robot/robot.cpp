#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

inline int myAbs(int x){
    return (x>0)?x:-x;
}

const int maxn=305;
const int tt=1e9+7;

int n,ans=0;
int a[maxn],b[maxn];
int h[maxn];

bool check(){
    for (int i=1;i<=n;i++){
        int cnt1=0,cnt2=0;
        for (int j=i-1;j>=1;j--) if (h[j]<=h[i]) cnt1++; else break;
        for (int j=i+1;j<=n;j++) if (h[j]<h[i]) cnt2++; else break;
        if (myAbs(cnt1-cnt2)>2) return false;
    }
    return true;
}

void DFS(int x){
    if (x==n){
        ans=(ans+check())%tt;
        return;
    }
    for (int i=a[x+1];i<=b[x+1];i++){
        h[x+1]=i;
        DFS(x+1);
    }
}

signed main(){
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
    if (n>7){
        printf("0\n");
        return 0;
    }
    DFS(0);
    printf("%lld\n",ans);
    return 0;
}