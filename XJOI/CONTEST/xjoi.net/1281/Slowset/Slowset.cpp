#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e5+5;

int n,m;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int fa[maxn];
int pos[maxn],cnt[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i])
		if (to[i]!=fa[x]) fa[to[i]]=x,build_tree(to[i]);
}

int mto[maxn];

void move_to(int x){
	#ifdef DEBUG
		printf("Move to %lld\n",x);
	#endif
	memset(mto,-1,sizeof(mto));
	int now=x;
	while (fa[now]!=0) mto[fa[now]]=now,now=fa[now];
	
	for (int i=1;i<=n;i++){
		#ifdef DEBUG
			printf("%lld -> ",pos[i]);
		#endif
		if (pos[i]!=x) pos[i]=((mto[pos[i]]!=-1)?mto[pos[i]]:fa[pos[i]]);
		#ifdef DEBUG
			printf("%lld\n",pos[i]);
		#endif
	}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}
	for (int i=1;i<=n;i++) pos[i]=i;
	build_tree(1);

	while (m--) move_to(read());

	for (int i=1;i<=n;i++) cnt[pos[i]]++;
	int ans=0;
	for (int i=1;i<=n;i++) ans+=cnt[i]>0;
	printf("%lld\n",ans);
	return 0;
}