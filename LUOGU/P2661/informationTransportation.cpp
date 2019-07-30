#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005;

int n,to[maxn],deep[maxn];

int fa[maxn];



void init(int n){
    for (int i=1;i<=n;i++) fa[i]=i;
}

signed main(){
    n=read();
    init(n);
    for (int i=1;i<=n;i++){
        to[i]=read();
        int fx=get_fa(i),fy=get_fa(to[i]);
    }
}