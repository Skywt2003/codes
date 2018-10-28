#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=200005,maxe=400005;
int n,tot=0,a[maxn],fa[maxn],sum[maxn],lnk[maxn],son[maxe],nxt[maxe],w[maxe];
long long dst[maxn];
bool vis[maxn];
vector <int> vec;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y,int z){
    tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline long long myabs(long long x){
    return x>0?x:-x;
}
inline void BuildDistance(int x){
    vis[x]=1;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        fa[son[i]]=x;
        dst[son[i]]=(long long)dst[x]+w[i];
        BuildDistance(son[i]);
    }
}
inline long long GetDistance(int x,int y){
    return myabs((long long)dst[x]-dst[y]);
}
inline void BuildSum(int x){
    vis[x]=1;
    int L=0,R=vec.size()-1,mid,now=-1;
    while (L<=R){
        mid=((R-L)>>1)+L;
        if ((long long)GetDistance(x,vec[mid])<=(long long)a[x]){
            now=mid;
            R=mid-1;
        } else L=mid+1;
    }
    if (now!=-1){
        now=vec[now];
        if (now!=x||GetDistance(x,now)<=a[x]) sum[fa[x]]++,sum[fa[now]]--;
    }
    vec.push_back(x);
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        BuildSum(son[i]);
    }
    vec.erase(vec.end()-1);
}
inline void GetAnswer(int x){
    vis[x]=1;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        GetAnswer(son[i]);
        sum[x]+=sum[son[i]];
    }
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=2;i<=n;i++){
        int x=read(),y=read();
        add(i,x,y);add(x,i,y);
    }
    BuildDistance(1);
    memset(vis,0,sizeof(vis));
    vec.clear();
    vec.push_back(1);
    BuildSum(1);
    memset(vis,0,sizeof(vis));
    GetAnswer(1);
    for (int i=1;i<=n;i++) printf("%d ",sum[i]);
    printf("\n");
    return 0;
}
