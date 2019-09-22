#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=10005;

int n;
int a[maxn];

bool vis[maxn];
bool flg=false;
int ans=0;

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();

    if (a[1]!=0){
        flg=true;
        vis[1]=1;
        for (int i=1;i<n;i++){
            int now=a[i]-vis[i-1]-vis[i];
            if (now<0 || now>1) {flg=false;break;}
            vis[i+1]=now;
        }
        if (vis[n]+vis[n-1]!=a[n]) flg=false;
        ans+=flg;
    }

    flg=true;
    vis[1]=0;
    for (int i=1;i<n;i++){
        int now=a[i]-vis[i-1]-vis[i];
        if (now<0 || now>1) {flg=false;break;}
        vis[i+1]=now;
    }
    if (vis[n]+vis[n-1]!=a[n]) flg=false;
    ans+=flg;

    printf("%d\n",ans);
    return 0;
}