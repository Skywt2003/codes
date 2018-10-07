/*
 * XJOI CONTEST1011
 * T1 UnderCity
 * 181003 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5005,maxe=10005;
int n,value[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],deep[maxn];
int f[maxn],sum[maxn];
bool vis[maxn];

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int build_deep(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa) deep[son[i]]=deep[x]+1,build_deep(son[i],x);
}

inline void DFS(int x,int fa){
	f[x]=0;
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa) DFS(son[i],x),f[x]+=sum[son[i]];
	sum[x]=f[x];
	
	vector <int> vec; vec.clear();
	memset_clear(vis);
	queue <int> que; while (!que.empty()) que.pop();
	que.push(x);vis[x]=true;vis[fa]=true;
	while (!que.empty()){
		int head=que.front();que.pop();
		for (int i=lnk[head];i;i=nxt[i]) if (!vis[son[i]]){
			if (value[son[i]]<value[x]) vec.push_back(value[son[i]]);
		}
	}
	sort(vec.begin(),vec.end());
	int count=0;
	for (int i=0;i<vec.size();){
		int j=i;
		while (j+1<vec.size() && vec[j+1]==vec[i]) j++;
		count+=(j-i+1)*i;i=j+1;
	}
	f[x]+=count;

	vec.clear();
	for (int i=1;i<=n;i++) if (deep[i]>deep[x] && value[i]<value[x]) vec.push_back(value[i]);
	sort(vec.begin(),vec.end());
	count=0;
	for (int i=0;i<vec.size();){
		int j=i;
		while (j+1<vec.size() && vec[j+1]==vec[i]) j++;
		count+=(j-i+1)*i;i=j+1;
	}
	sum[x]+=count;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) value[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	build_deep(1,-1);
	DFS(1,-1);
	for (int i=1;i<n;i++) printf("%lld ",f[i]);
	printf("%lld\n",f[n]);
	return 0;
}