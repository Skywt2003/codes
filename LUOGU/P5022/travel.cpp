#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5005,maxe=10005;

int n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
pair<int,int> edges[maxn];
bool vis[maxn];

int ans[maxn],now[maxn];
pair<int,int> now_block;

int son[maxn][maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

bool check(int x,int y){
	if (x==now_block.first && y==now_block.second) return false;
	if (y==now_block.first && x==now_block.second) return false;
	return true;
}

void DFS(int x){
	vis[x]=true; now[++now[0]]=x;
	for (int i=1;i<=son[x][0];i++)
		if (!vis[son[x][i]] && check(x,son[x][i])) DFS(son[x][i]);
}

bool smaller(){
	for (int i=1;i<=n;i++)
		if (now[i]<ans[i]) return true; else
		if (now[i]>ans[i]) return false;
	return false;
}

int main(){
	#ifdef DEBUG
		freopen("testdata.in","r",stdin);
		freopen("my.out","w",stdout);
	#endif
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
		son[x][++son[x][0]]=y;
		son[y][++son[y][0]]=x;
		edges[i]=make_pair(x,y);
	}
	for (int i=1;i<=n;i++) sort(son[i]+1,son[i]+1+son[i][0]);

	if (m==n-1){
		DFS(1);
		for (int i=1;i<=n;i++) printf("%d ",now[i]);
		printf("\n");
	} else {
		for (int i=1;i<=m;i++){
			memset(vis,0,sizeof(vis));
			now_block=edges[i]; now[0]=0;
			DFS(1);
			if (now[0]!=n) continue;
			if (ans[0]==0 || smaller())
				for (int j=0;j<=n;j++) ans[j]=now[j];
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}