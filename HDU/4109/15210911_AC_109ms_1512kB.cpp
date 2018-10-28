#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1005,maxe=10005;
int n,m,tme[maxn],ans=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe],ind[maxn];
queue<int> que;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void Init(){
	tot=ans=0;
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	memset(son,-1,sizeof(son));
	memset(ind,0,sizeof(ind));
	memset(w,0,sizeof(w));
	memset(tme,0,sizeof(tme));
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;ind[y]++;
}
inline void Topology(){
	for (int i=0;i<n;i++) if (!ind[i]) que.push(i);
	while (!que.empty()){
		int x=que.front();que.pop();
		for (int i=lnk[x];i!=-1;i=nxt[i]){
			ind[son[i]]--;
			tme[son[i]]=max(tme[son[i]],tme[x]+w[i]);
			ans=max(ans,tme[son[i]]);
			if (!ind[son[i]]) que.push(son[i]);
		}
	}
}
int main(){
	while (scanf("%d%d",&n,&m)!=-1){
		Init();
		for (int i=0;i<m;i++){
			int x=read(),y=read(),z=read();
			add(x,y,z);
		}
		Topology();
		printf("%d\n",ans+1);
	}
	return 0;
}