#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=300005,maxe=600005;

int n,ans=0,a[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int f[maxn];

struct sons{
	int id,num,w;
};
vector<sons> vec;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline bool cmp(sons aa,sons bb){
	return aa.num>bb.num;
}

inline void DFS(int x,int from){
	vec.clear();sons fi=(sons){0,0,0},se=(sons){0,0,0};
	for (int i=lnk[x];i;i=nxt[i]) vec.push_back((sons){son[i],f[son[i]],w[i]}),ans=max(ans,a[x]+f[son[i]]);
	if ((int)vec.size()==0) return;
	sort(vec.begin(),vec.end(),cmp);
	fi=vec[0];if ((int)vec.size()>1) se=vec[1];
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=from){
		int maxnum=((son[i]==fi.id)?(se.num):(fi.num)) +a[x]-w[i];
		if (maxnum<0) maxnum=0;
		int tmp=f[x];
		f[x]=maxnum;
		DFS(son[i],x);
		f[x]=tmp;
	}
}

inline void build_tree(int x,int fa,int wfa){
	f[x]=a[x]-wfa;
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		build_tree(son[i],x,w[i]);
		f[x]=max(f[x],f[son[i]]+a[x]-wfa);
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),ans=max(ans,a[i]);
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}
	build_tree(1,-1,0);
	DFS(1,-1);
	printf("%lld\n",ans);
	return 0;
}