#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=15;
int n,m,ans=1<<30,INF=1<<30;
struct MagicInfo{
    int effect,special;
}a[maxn];
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void DFS(int step,int blood){
    if (step>ans) return;
    if (blood<=0){ans=min(ans,step);return;}
    int now_blood;
    for (int i=1;i<=n;i++) if (!vis[i]){
        vis[i]=1;
        if (a[i].special>=blood) now_blood=blood-2*a[i].effect; else now_blood=blood-a[i].effect;
        DFS(step+1,now_blood);
        vis[i]=0;
    }
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i].effect=read(),a[i].special=read();
    DFS(0,m);
    if (ans==INF) printf("-1\n"); else printf("%d\n",ans);
    return 0;
}