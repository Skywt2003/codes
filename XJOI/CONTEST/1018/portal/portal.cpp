#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1000005,maxe=2000005;
int n,ans=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int f[maxn],mxd[maxn];

inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void make_sub(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		make_sub(son[i],x);
		mxd[x]=max(mxd[son[i]]+w[i],mxd[x]);
		f[x]+=max(mxd[son[i]]+w[i],f[son[i]]);
	}
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
		ans+=2*z;
	}
	make_sub(1,-1);
	ans-=f[1];
	printf("%lld\n",ans);
	return 0;
}
