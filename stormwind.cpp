/*
 * XJOI CONTEST1011
 * T2 StormWind
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

const int maxn=2e5+10,maxe=4e5+10;
int n,m,k;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
bool vis_v[maxn],vis_e[maxn];
bool vis[maxn];
struct Edge{
	int x,y;
}a[maxe];
queue <int> que;

struct way{
	int x,id;
};

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

way DFS(int x){
	vis[x]=true;
	way ret;ret=(way){0,0};
	for (int i=lnk[x];i;i=nxt[i]) if ((!vis[son[i]])&&(vis_e[son[i]])&&(vis_v[son[i]])){
		way now=DFS(son[i]);
		if (now.x>ret.x) ret=now;
	}
	ret.x++;
	return ret;
}

inline bool cmp(way aa,way bb){
	return aa.x>bb.x;
}

way DFS(int x,way fst){
	vis[x]=true;
	vector<way> ways;ways.clear();
	for (int i=lnk[x];i;i=nxt[i]) if ((!vis[son[i]])&&(vis_e[son[i]])&&(vis_v[son[i]])) ways.push_back(DFS(son[i]));
	sort(ways.begin(),ways.end(),cmp);
	ways[1].x++;
	return ways[1];
}

signed main(){
	memset_clear_tre(vis_v);
	memset_clear_tre(vis_e);
	n=read();m=read();k=read();
	for (int i=1;i<=m;i++){
		a[i].x=read(),a[i].y=read();
		add(a[i].x,a[i].y);add(a[i].y,a[i].x);
	}
	while (k--){
		int cmd=read(),x=read();
		if (cmd==1){
			vis_v[x]=false;
			memset_clear(vis);
			way now=DFS(1);
			memset_clear(vis);
			way rel=DFS(now.id);
			printf("%lld\n",rel.x);
			vis_v[x]=true;
		} else if (cmd==2){
			memset_clear(vis);
			way now=DFS(x);
			memset_clear(vis);
			way rel=DFS(x,now);
			printf("%lld\n",now.x+rel.x);
		} else if (cmd==3){
			vis_e[x<<1]=vis_e[(x<<1)-1]=false;
			memset_clear(vis);
			way now1=DFS(a[x].x);
			way now2=DFS(a[x].y);
			printf("%lld\n",now1.x+now2.x+1);
			vis_e[x<<1]=vis_e[(x<<1)-1]=true;
		}
	}
	return 0;
}