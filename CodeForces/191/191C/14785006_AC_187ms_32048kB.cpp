#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,m,deep[maxn],sum[maxn],fa[maxn],f[maxn][20];
struct SideData{
    int x,id;
};
SideData que[maxn];
vector <SideData> lnk[maxn],son[maxn],ans;
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool Compare(SideData aa,SideData bb){
    return aa.id<bb.id;
}
inline int lowbit(int x){
    return x&(-x);
}
inline void BuildTree(int x,int d){
    vis[x]=1;
    for (int i=0;i<lnk[x].size();i++) if (!vis[lnk[x][i].x]){
        deep[lnk[x][i].x]=d+1;
        fa[lnk[x][i].x]=x;
        son[x].push_back((SideData){lnk[x][i].x,lnk[x][i].id});
        BuildTree(lnk[x][i].x,d+1);
    }
}
inline void BuildLCA(){
    for (int i=1;i<=n;i++) f[i][0]=fa[i];
    for (int j=1;j<20;j++)
        for (int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
}
inline int GetLCA(int x,int y){
    if (deep[x]>deep[y]) swap(x,y);
    for (int i=19;i>=0;i--) if (deep[f[y][i]]>=deep[x]) y=f[y][i];
    if (x==y) return x;
    for (int i=19;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
inline int GetAnswer(int x){
    int ret=sum[x];
    for (int i=0;i<son[x].size();i++) {
        int now_ans=GetAnswer(son[x][i].x);
        ans.push_back((SideData){now_ans,son[x][i].id});
        ret+=now_ans;
    }
//    printf("X=%d  Result=%d\n",x,ret);
    return ret;
}
int main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        lnk[x].push_back((SideData){y,i});
        lnk[y].push_back((SideData){x,i});
    }
    deep[1]=1;BuildTree(1,1);
//    for (int i=1;i<=n;i++) printf("DEEP[%d]=%d\n",i,deep[i]);
//    for (int i=1;i<=n;i++){
//        printf("%d: ",i);
//        for (int j=0;j<son[i].size();j++) printf("%d ",son[i][j].x);
//        printf("\n");
//    }
    BuildLCA();
    m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        sum[x]++;sum[y]++;
        sum[GetLCA(x,y)]-=2;
    }
    GetAnswer(1);
    sort(ans.begin(),ans.end(),Compare);
    for (int i=0;i<ans.size();i++) printf("%d ",ans[i].x);
    printf("\n");
    return 0;
}
