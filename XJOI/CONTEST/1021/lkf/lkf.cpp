#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int tt=19260817;
const int maxn=3333+10,maxe=maxn*2;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,k;
int a[maxn];
int tot=0,lnk[maxn],son[maxe],nxt[maxe];
struct vertex{
	int x,id;
};
vector<vertex> v;
int ans=0;
bool vis[maxn];

inline void add(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline bool compare(vertex aa,vertex bb){
	return (aa.x<bb.x)||(aa.x==bb.x&&aa.id<bb.id);
}

inline int DFS(int x,int fa,int k,int st){
	int ret=1;
	for (int i=lnk[x];i;i=nxt[i]) if (a[son[i]]<=st+k && son[i]!=fa && (!vis[son[i]])) ret=(ret*DFS(son[i],x,k,st))%tt;
	return (ret+(fa!=-1))%tt;
}

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read(),v.push_back((vertex){a[i],i});
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	sort(v.begin(),v.end(),compare);
	for (int i=0;i<n;i++){
		vis[v[i].id]=true;
		if (k==0) ans=(ans+DFS(v[i].id,-1,k,v[i].x))%tt;
		else ans=(ans+(DFS(v[i].id,-1,k,v[i].x)-DFS(v[i].id,-1,k-1,v[i].x)+tt)%tt)%tt;
	}
	printf("%lld\n",ans);
	return 0;
}