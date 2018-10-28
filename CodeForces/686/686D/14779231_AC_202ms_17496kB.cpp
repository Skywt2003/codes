#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=300005;
int n,q,fa[maxn],sum[maxn],ans[maxn];
vector <int> lnk[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void DFS(int x){
    sum[x]=1;ans[x]=x;
    for (int i=0;i<lnk[x].size();i++) DFS(lnk[x][i]),sum[x]+=sum[lnk[x][i]];
    for (int i=0;i<lnk[x].size();i++) if (sum[lnk[x][i]]*2>sum[x]) {ans[x]=ans[lnk[x][i]];break;}
    while ((sum[x]-sum[ans[x]])*2>sum[x]) ans[x]=fa[ans[x]];
}
int main(){
    n=read();q=read();
    for (int i=2;i<=n;i++){
        int x=read();
        lnk[x].push_back(i);
        fa[i]=x;
    }
    DFS(1);
    for (int i=1;i<=q;i++) printf("%d\n",ans[read()]);
    return 0;
}
