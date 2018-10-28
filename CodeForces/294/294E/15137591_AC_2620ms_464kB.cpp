#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=5005,maxe=10005;
int n,sum_son[maxn],max_sub[maxn],c[2],tmp[2],flag[maxn],num[2],sum_dfs=0;
long long ans=(long long)1<<60,total_sum[2],lst[maxn],lstw[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe],dst[2][maxn];
bool can_use[maxe],vis[maxn];
struct EdgeData{
    int x,y,w;
}e[maxn];
inline void add(int x,int y,int z){
    tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int BuildNumber(int x){ // 先要求出两个联通块点的个数，不然后面求重心没法做……
    // 我是拒绝的 qwq
    vis[x]=true;
    int ret=1;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]&&can_use[i]) ret+=BuildNumber(son[i]);
    return ret;
}
inline void Build(int x,int k){ // 求重心……
    flag[x]=k;
    vis[x]=true;
    max_sub[x]=0;sum_son[x]=0;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]&&can_use[i]){
        Build(son[i],k);
        max_sub[x]=max(max_sub[x],max(max_sub[son[i]],sum_son[son[i]]+1));
        sum_son[x]+=sum_son[son[i]]+1;
    }
    if (max(num[k]-sum_son[x],max_sub[x])<tmp[k]) tmp[k]=max(num[k]-sum_son[x],max_sub[x]),c[k]=x;
}
inline void GetDist(int x,int k){
    vis[x]=true; 
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]&&flag[son[i]]==k){
        dst[k][son[i]]=dst[k][x]+w[i];
        GetDist(son[i],k);
    }
}
inline int GetSum(int x,int k){ // 还要写个构造联通块内两两节点距离之和的函数 (吐血)
    sum_dfs++;
    vis[x]=1;
    total_sum[k]+=lst[x];
    int van=0;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]&&can_use[i]){
        lst[son[i]]=lst[x]+(long long)sum_dfs*w[i];
        int nowvan=GetSum(son[i],k);
        lst[x]+=lstw[son[i]]+(long long)(nowvan)*w[i];     // !!!!!!!!!!
        lstw[x]+=lstw[son[i]]+(long long)(nowvan)*w[i];
        van+=nowvan;
    }
    van++;
    return van;
}
int main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z);add(y,x,z);
        e[i].x=x;e[i].y=y;e[i].w=z;
    }
    memset(can_use,true,sizeof(can_use));
    for (int i=1;i<n;i++){
        memset(c,0,sizeof(c));
        memset(tmp,63,sizeof(tmp));
        memset(dst,0,sizeof(dst));
        memset(flag,255,sizeof(flag));
        memset(sum_son,0,sizeof(sum_son));
        memset(max_sub,0,sizeof(max_sub));
        
        long long cen_left=0,cen_right=0,sum_left=0,sum_right=0,num_left=0,num_right=0;
        can_use[i*2]=can_use[i*2-1]=false;

        memset(vis,0,sizeof(vis));
        num_left=num[0]=BuildNumber(e[i].x);num_right=num[1]=BuildNumber(e[i].y);
        memset(vis,0,sizeof(vis));
        Build(e[i].x,0);
        Build(e[i].y,1);
        cen_left=c[0];cen_right=c[1];
        //printf("Cen_Left: %d  Cen_Right: %d  Num_Left: %d  Num_Right: %d\n",cen_left,cen_right,num_left,num_right);

        memset(vis,0,sizeof(vis));
        GetDist(cen_left,0);
        GetDist(cen_right,1);
        for (int j=1;j<=n;j++){
            if (flag[j]==0) sum_left +=dst[0][j]; else
            if (flag[j]==1) sum_right+=dst[1][j];
        }

        memset(total_sum,0,sizeof(total_sum));
        memset(vis,0,sizeof(vis));
        memset(lst,0,sizeof(lst));
        memset(lstw,0,sizeof(lstw));
        sum_dfs=0;GetSum(e[i].x,0);
        sum_dfs=0;GetSum(e[i].y,1);
        //printf("TOTSUM0: %d  TOTSUM1: %d\n",total_sum[0],total_sum[1]);
        long long now=(long long)num_right*sum_left+(long long)num_left*sum_right+(long long)num_left*num_right*e[i].w+total_sum[0]+total_sum[1];
        //printf("Result: %d\n",now);
        if (now<ans) ans=now;
        can_use[i*2]=can_use[i*2-1]=true;
    }
    printf("%lld\n",ans);
    return 0;
}
