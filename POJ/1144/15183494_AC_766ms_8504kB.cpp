#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,maxe=1000005;
int n,fa[maxn];
int tot=0,acnt=0,dfn[maxn],low[maxn];
int lnk[maxn],nxt[maxe],son[maxe];
bool vis[maxn],ans[maxn];
inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Init(){
	tot=0;acnt=0;
	memset(fa,0,sizeof(fa));
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(son,0,sizeof(son));
	memset(vis,0,sizeof(vis));
	memset(dfn,0,sizeof(dfn));
	memset(ans,0,sizeof(ans));
}
inline void DFS(int x){
	vis[x]=1;dfn[x]=low[x]=++acnt;
	int nowson=0;
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
		nowson++;
		fa[son[i]]=x;
		DFS(son[i]);
		low[x]=min(low[x],low[son[i]]);
		if (x!=1&&low[son[i]]>=dfn[x]) ans[x]=true;
		if (x==1&&nowson>=2) ans[x]=true;
	} else if (son[i]!=fa[x]) low[x]=min(dfn[son[i]],low[x]);
}
int main(){
	for (;;){
		scanf("%d",&n);if (n==0) break;
		Init();int ans_cnt=0;
		int x;scanf("%d",&x);
		while (x!=0){
			int now=0;char ch=getchar();
			while (ch!=10&&ch!=13){
				while ((ch<'0'||ch>'9')&&ch!=10&&ch!=13) ch=getchar();
				if (ch==10||ch==13) break;
				while (ch>='0'&&ch<='9') now=now*10+ch-'0',ch=getchar();
				add(x,now);add(now,x);
				now=0;
			}
			scanf("%d",&x);
		}
		DFS(1);
		for (int i=1;i<=n;i++) ans_cnt+=ans[i];
		printf("%d\n",ans_cnt);
	}
	return 0;
}