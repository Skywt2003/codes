#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
const int maxs=(1<<20)+5;

int T;
int n,m,to;
int c,bnum;
int a[maxn];

int f[maxs];

void init(){
	memset(f,0,sizeof(f));
	bnum=0;
}

void build_dp(){
	for (int i=0;i<m;i++){
		int now=bnum<<i;
		if (now >= (1<<m)) break;
		for (int j=0;j<(1<<m);j++) if ((j&now)==now) f[j-now]+=f[j];
	}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	T=read();
	while (T--){
		init();
		n=read();m=read();
		for (int i=1;i<=n;i++) a[i]=read(),f[a[i]]++;
		c=read();
		bnum=1;
		for (int i=1;i<=c;i++) bnum|=1<<read();

		build_dp();

		int q=read();
		while (q--) printf("%d\n",f[read()]);
	}
	return 0;
}