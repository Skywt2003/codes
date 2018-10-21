#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
#define int long long
#define sqr(_) ((_)*(_))

const int tt=998244353;
const int maxn=1005,maxe=2005;
int n,a[maxn],d[maxn],f[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],p[maxn];
int fa[maxn];
int ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y;p[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),d[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	
	return 0;
}