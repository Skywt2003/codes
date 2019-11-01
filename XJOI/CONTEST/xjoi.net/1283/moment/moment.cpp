#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;

int n,q,type,num;
int fa[maxn];
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int clr[maxn];
int b[maxn],w[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

int get_color(int x,int k){
	if (clr[x]!=-1){b[x]=clr[x]; w[x]=1-clr[x];return clr[x];}
	b[x]=w[x]=0;
	for (int i=lnk[x];i;i=nxt[i]){
		get_color(to[i],k);
		b[x]+=b[to[i]]; w[x]+=w[to[i]];
	}
	if (b[x]-w[x]>=k){b[x]++;return 1;}
	else {w[x]++;return 0;}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif

	num=read();
	if (num==3) return 0;
	n=read(); q=read(); type=read();
	for (int i=2;i<=n;i++) fa[i]=read(),add_edge(fa[i],i);
	for (int i=1;i<=n;i++) clr[i]=read();

	int last_ans=0;
	while (q--){
		int opt=read(),x=read(),y=read();
		if (type) x^=last_ans;
		if (opt==2) clr[x]=y; else printf("%lld\n",last_ans=get_color(x,y));
	}

	return 0;
}