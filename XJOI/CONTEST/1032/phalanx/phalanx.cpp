#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=1005,maxm=4005;
int n,m;
int tot=0,lnk[maxn],nxt[2*maxm],son[2*maxm];
int ans;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y+n);add_edge(y+n,x);
	}
	
	printf("%lld\n",ans);
	return 0;
}