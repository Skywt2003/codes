#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005,maxe=2005;
int n,ans=0;
int fa[maxn],deep[maxn];
int f[maxn];

struct node{
    int x,deep;

    bool operator <(node bb)const{
        return deep<bb.deep;
    }
};

node make_node(int x,int y){
    node ret; ret.x=x;ret.deep=y;
    return ret;
}

priority_queue<node> heap;

bool check(int x){
    if (f[x]) return true;
    if (f[fa[x]] && deep[f[fa[x]]]<=deep[x]) return true;
    if (f[fa[fa[x]]] && f[fa[fa[x]]]==fa[fa[x]]) return true;
    return false;
}

#define grandfa(x) (fa[fa[x]])

signed main(){
    n=read();
    deep[1]=1; heap.push(make_node(1,deep[1]));
    for (int i=2;i<=n;i++)
        fa[i]=read(),deep[i]=deep[fa[i]]+1,heap.push(make_node(i,deep[i]));

    while (!heap.empty()){
        node now=heap.top(); heap.pop();
        while (!heap.empty() && check(now.x)) now=heap.top(),heap.pop();
        if (heap.empty() && check(now.x)) break;
        ans++;
        int setx=grandfa(now.x); setx=(setx==0)?1:setx;
        // printf("now.x= %lld, Put: %lld\n",now.x,setx);
        f[setx] = f[fa[setx]] = f[grandfa(setx)] = setx;
    }

    printf("%lld\n",ans);
    return 0;
}