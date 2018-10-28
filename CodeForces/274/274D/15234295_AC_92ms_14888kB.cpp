#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=200005,maxe=400005;
int n,m,cnt=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],ind[maxe];
struct WT{
	int x,id;
}ans[maxn];
vector<int> a[maxn];
vector<WT> rcd[maxn];
queue<int> que;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y){
	x++;y++;
	tot++;ind[y]++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
	//printf("Add an edge: %d  -> %d\n",x,y);
}
inline bool cmp(WT aa,WT bb){
	return aa.x<bb.x;
}
inline void Build(int k){
	for (int i=1;i<=m;i++) ans[i].id=i;
	int s=-1;bool fst=true;
	while (rcd[k][s+1].x==-1) s++;
	for (int i=s+1;i<m;){
		int j=i;cnt++;
		if (!fst) add(cnt-1+m,rcd[k][i].id);
		while (rcd[k][j+1].x==rcd[k][i].x&&j+1<m){
			j++;
			if (!fst) add(cnt-1+m,rcd[k][j].id);
		}
		fst=false;
		if (j+1<m) for (int t=i;t<=j;t++) add(rcd[k][t].id,cnt+m);
		i=j+1;
	}
}
inline void Topology(){
	for (int i=1;i<=m;i++) if (ind[i]==0) ans[i].x=1,que.push(i);
	while (!que.empty()){
		int x=que.front();que.pop();
		for (int i=lnk[x];i;i=nxt[i]){
			ind[son[i]]--;
			ans[son[i]].x=max(ans[son[i]].x,ans[x].x+bool(son[i]<=m));
			if (ind[son[i]]==0) que.push(son[i]);
		}
	}
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		for (int j=0;j<m;j++){
			int now=read();
			a[i].push_back(now);
			rcd[i].push_back((WT){now,j});
		}
		sort(rcd[i].begin(),rcd[i].end(),cmp);
	}
	for (int i=1;i<=n;i++) Build(i);
	Topology();
	sort(ans+1,ans+1+m,cmp);
	if (ans[1].x==0){printf("-1\n");return 0;}
	for (int i=1;i<=m;i++) printf("%d ",ans[i].id);
	printf("\n");
	return 0;
}