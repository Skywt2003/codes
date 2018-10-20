#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;

const int maxn=1001005,maxe=1001005;
int n,m,s_rain,t_rain,ind[maxn],num[maxn],water[maxn],que[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;ind[y]++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void Topology(){
	int head=0,tail=0;
	for (int i=1;i<=m;i++) que[++tail]=i;
	while (head!=tail){
		head++;
		for (int i=lnk[que[head]];i;i=nxt[i]){
			ind[son[i]]--;
			num[son[i]]=max(num[son[i]],num[que[head]]+water[que[head]]*w[i]);
			water[son[i]]+=water[que[head]];
			if (ind[son[i]]==0) que[++tail]=son[i];
		}
	}
}

signed main(){
	n=read();m=read();s_rain=read();t_rain=read();
	for (int i=1;i<=m;i++){
		int s=read(),h=read(),y=read(),z=read();
		int now=s*s_rain*t_rain;
		water[i]=min(now,s*h);
		add(i,y+m,z);
	}
	for (int i=m+1;i<m+n;i++){
		int y=read(),z=read();
		add(i,y+m,z);
	}
	Topology();
	int ans=0;
	for (int i=1;i<=n+m;i++) ans=max(ans,num[i]);
	printf("%lld\n",ans);
	return 0;
}