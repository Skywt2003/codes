#define CLEAR(x) memset(x,0,sizeof(x))

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int T,n,m,a[maxn],t[32*maxn][2],tot=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void insert(int x){
	int p=0;
	for (int i=31;i>=0;i--){
		int now=(bool)(x&(1<<i));
		if (!t[p][now]) t[p][now]=++tot;
		p=t[p][now];
	}
}
inline int query(int x){
	int p=0,ret=0;
	for (int i=31;i>=0;i--){
		int nxt=0;
		if (x&(1<<i)){
			if (t[p][0]) p=t[p][0]; else p=t[p][1],nxt=1;
		} else {
			if (t[p][1]) p=t[p][1],nxt=1; else p=t[p][0];
		}
		// printf("%d %d\n",t[p][0],t[p][1]);
		ret+=nxt*(1<<i);
	}
	return ret;
}

int main(){
	T=read();
	int cnt=0;
	while (T--){
		printf("Case #%d:\n",++cnt);
		CLEAR(t);tot=0;
		n=read();m=read();
		for (int i=1;i<=n;i++) a[i]=read(),insert(a[i]);
		for (int i=1;i<=m;i++){
			int x=read();
			printf("%d\n",query(x));
		}
	}
	return 0;
}