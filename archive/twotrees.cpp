#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int v,n1,n2,m,ans=0,to[maxn];
bool vis[maxn],lnk[maxn][maxn];
  
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

inline bool Find(int x){
    if (vis[x]) return false;
    vis[x]=true;
    for (int i=1;i<=n2;i++) if (lnk[x][i]){
        if (to[i]==0||Find(to[i])){
            to[i]=x;
            return true;
        }
    }
    return false;
}

int main(){
    v=read();v++;n1=read();n2=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        lnk[x][y]=true;
    }
    for (int i=1;i<=n1;i++){
        memset(vis,0,sizeof(vis));
        ans+=Find(i);
    }
    printf("%d\n",min(n1+n2-ans,v));
    return 0;
}