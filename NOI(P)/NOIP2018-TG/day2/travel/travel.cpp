#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5005,maxe=10005;
int n,m;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
bool can_use[maxn+1],vis[maxn];
vector<int> sons[maxn];

vector<int> ans,now;

inline void add_edge(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void DFS(int x,int lst){
	vis[x]=true;
	now.push_back(x);
	sons[x].clear();
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=lst && can_use[(i+1)>>1]==true){
		if (vis[son[i]]) continue;
		sons[x].push_back(son[i]);
	}
	sort(sons[x].begin(),sons[x].end());
	for (int i=0;i<(int)sons[x].size();i++) DFS(sons[x][i],x);
}

inline bool smaller(vector<int> &aa,vector<int> &bb){
	for (int i=0;i<(int)aa.size();i++) if (aa[i]<bb[i]) return true; else if (aa[i]>bb[i]) return false;
	return false;
}

int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	memset(can_use,1,sizeof(can_use));
	if (m==n-1){
		now.clear();
		DFS(1,-1);
		for (int i=0;i<(int)now.size()-1;i++) printf("%d ",now[i]);
		printf("%d\n",now[now.size()-1]);
	} else {
		for (int i=1;i<=m;i++){
			can_use[i]=false;
			memset(vis,0,sizeof(vis));
			now.clear();DFS(1,-1);
			if (((int)now.size() == n) && ((int)ans.size()==0 || smaller(now,ans))) ans=now;
			can_use[i]=true;
		}
		for (int i=0;i<(int)ans.size()-1;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[ans.size()-1]);
	}
	return 0;
}
