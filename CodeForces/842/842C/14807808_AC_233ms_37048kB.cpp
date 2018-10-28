// #pragma GCC optimize(2)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,a[maxn],ans[maxn];
vector <int> lnk[maxn];
set <int> s;
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
inline void DFS(int x,set <int> now,int v){
    vis[x]=1;
    for (int i=0;i<lnk[x].size();i++) if (!vis[lnk[x][i]]){
        int son_now=lnk[x][i];
        vis[son_now]=1;
        set <int> nxt;nxt.clear();nxt.insert(v);
        set <int>::iterator it;
        for (it=now.begin();it!=now.end();it++) nxt.insert(gcd(*it,a[son_now]));
        ans[son_now]=max(ans[son_now],*nxt.rbegin());
        DFS(son_now,nxt,gcd(v,a[son_now]));
    }
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        lnk[x].push_back(y);
        lnk[y].push_back(x);
    }
    s.clear();
    s.insert(a[1]);s.insert(0);
    ans[1]=a[1];DFS(1,s,a[1]);
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
