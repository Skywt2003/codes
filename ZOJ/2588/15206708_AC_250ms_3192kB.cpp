#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=10005,maxe=200005;
int T,n,m,fa[maxn];
int tot=0,acnt=0,dfn[maxn],low[maxn];
int lnk[maxn],nxt[maxe],son[maxe],id[maxe];
bool vise[maxe],ans[maxe],vis[maxn];
vector<int> que_ans;
inline void add(int x,int y,int z){
	tot++;son[tot]=y;id[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Init(){
	tot=0;acnt=0;que_ans.clear();
	memset(fa,0,sizeof(fa));
	memset(id,0,sizeof(id));
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(son,0,sizeof(son));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(ans,1,sizeof(ans));
	memset(vis,0,sizeof(vis));
}
inline void DFS(int x){
	dfn[x]=low[x]=++acnt;
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
		fa[son[i]]=id[i];vis[son[i]]=true;
		DFS(son[i]);
		if (low[son[i]]<=dfn[x]) ans[id[i]]=false;
		low[x]=min(low[x],low[son[i]]);
	} else if (id[i]!=fa[x]) low[x]=min(dfn[son[i]],low[x]),ans[id[i]]=false;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		Init();
		for (int i=1;i<=m;i++){
			int x,y;scanf("%d%d",&x,&y);
			add(x,y,i);add(y,x,i);
		}
		vis[1]=true;DFS(1);
		
		for (int i=1;i<=m;i++) if (ans[i]) que_ans.push_back(i);
		int nn=que_ans.size();printf("%d\n",nn);
		for (int i=0;i<nn-1;i++) printf("%d ",que_ans[i]);
		if (nn!=0) printf("%d\n",que_ans[nn-1]);
		// printf("LOW: ");for (int i=1;i<=n;i++) printf("%d ",low[i]);printf("\n");
		// printf("DFN: ");for (int i=1;i<=n;i++) printf("%d ",dfn[i]);printf("\n");
		if (T>0) printf("\n");
	}
	return 0;
}