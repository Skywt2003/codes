#include<bits/stdc++.h>

using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2005,maxs=2520;

int n,v[maxn];
int m[maxn],k[15],lnk[maxn*maxs],rlnk[maxn*maxs];
int q;

int ans[maxn*maxs];
int deep[maxn*maxs],onl[maxn*maxs];
bool vis[maxn*maxs],cnd[maxn];

int DFS(int x,int y,int fa){
    int now=(x-1)*maxs+y;
    if (ans[now]!=-1) return ans[now];

    deep[now]=deep[fa]+1; onl[deep[now]]=x;
    vis[now]=true;
    if (vis[lnk[now]]){
        for (int i=deep[lnk[now]];i<=deep[now];i++) if (!cnd[onl[i]]) ans[now]++,cnd[onl[i]]=true;
        for (int i=deep[lnk[now]];i<=deep[now];i++) cnd[onl[i]]=false;
    } else ans[now]=DFS(rlnk[now],(y+v[x])%maxs,now);
    vis[now]=false;
    return ans[now];
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) v[i]=read(),v[i]=(v[i]%maxs+maxs)%maxs;
    for (int i=1;i<=n;i++){
        m[i]=read();
        for (int j=0;j<m[i];j++) k[j]=read();
        for (int j=0;j<maxs;j++){
            int nowto=(j+v[i])%maxs;
            lnk[(i-1)*maxs+j]=(k[nowto%m[i]]-1)*maxs+nowto;
            rlnk[(i-1)*maxs+j]=k[nowto%m[i]];
            ans[(i-1)*maxs+j]=-1;
        }
    }

    for (int i=1;i<=n;i++)
        for (int j=0;j<maxs;j++)
            if (ans[(i-1)*maxs+j]==-1) DFS(i,j,(i-1)*maxs+j);
    
    q=read();
    while (q--){
        int x=read(),c=read();
        c=(c%maxs+maxs)%maxs;
        printf("%d\n",ans[(x-1)*maxs+c]+1);
    }
    return 0;
}