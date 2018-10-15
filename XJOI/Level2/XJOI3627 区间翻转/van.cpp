#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000005;
int n,m,a[maxn],ls[maxn],rs[maxn],stk[maxn],top=0,root;
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void Build(){
    for (int i=1;i<=n;i++){
        if (a[i]>a[stk[top]]||top==0) rs[stk[top]]=i,stk[++top]=i; else {
            while (a[stk[top]]>a[i]&&top>=0) top--;
            ls[i]=stk[top+1];
            rs[stk[top]]=i;
            stk[++top]=i;
        }
    }
    root=stk[1];
}
inline void DFS(int x,int f){
    if (x==0) return;
    if (vis[a[x]]) vis[a[x]]=0,f=1-f;
    if (f) DFS(rs[x],f); else DFS(ls[x],f);
    printf("%d ",a[x]);
    if (f) DFS(ls[x],f); else DFS(rs[x],f);
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    Build();
    // for (int i=1;i<=n;i++) printf("%d %d\n",ls[i],rs[i]);
    for (int i=1;i<=m;i++){
        int x=read();
        vis[x]=1-vis[x];
    }
    DFS(root,0);
    printf("\n");
    return 9;
}