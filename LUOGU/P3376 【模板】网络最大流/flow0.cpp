//My first network-flows code.
//By: https://www.cnblogs.com/SYCstudio/p/7260613.html

//Dinic with cur.
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005,maxe=200005;
int n,m,s,t,tot=-1,ans=0,nxt[maxe],son[maxe],w[maxe],deep[maxn],lnk[maxn],que[maxn],cur[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline bool BFS(){//这个函数的作用是构造分层图同时返回有无增广路 
	memset(deep,0,sizeof(deep));
	deep[s]=1;//源点的深度为1 
	int head=0,tail=1;que[tail]=s;
	while (head!=tail){
		head++;
		for (int i=lnk[que[head]];i!=-1;i=nxt[i]) if (w[i]>0&&deep[son[i]]==0) deep[son[i]]=deep[que[head]]+1,que[++tail]=son[i];
	}
	if (deep[t]==0) return 0;//如果汇点深度为0说明没有被修正到，也就是说没有增广路 
	return 1;
}
inline int DFS(int x,int now){//x为当前点，now为当前流量 
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (deep[son[i]]==deep[x]+1&&w[i]!=0){
		int nxtd=DFS(son[i],min(now,w[i]));
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;//反向边加  
			return nxtd;//向上传递 
		}
	}
	return 0;
}
inline void Dinic(){
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,1<<30)) ans+=now;//初始流量为正无穷 
	}
}
int main(){
	memset(lnk,-1,sizeof(lnk));//因为边号从0开始存储，所以-1表示没有边 
	memset(nxt,-1,sizeof(nxt));
	n=read();m=read();s=read();t=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,0);//构造反向边并且其边号与正向边相邻 
	}
	Dinic();
	printf("%d\n",ans);
	return 0;
}
