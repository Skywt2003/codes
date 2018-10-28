#define maxe maxm

#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=505,maxm=20005,maxd=21,maxs=32780;
int t,n,m,d,s,tot=0,INF,lnk[maxn],son[maxe],nxt[maxe],f[maxs][maxd],w[maxe],shop[maxd],dst[maxd][maxn];
bool vis[maxn];
struct HeapElementData{
	int x,id;
	bool operator <(const HeapElementData aa)const{
		return x>aa.x;
	}
};
priority_queue <HeapElementData> heap;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Dijkstra(int num,int st){
	while (heap.size()>0) heap.pop();
	memset(vis,0,sizeof(vis));
	dst[num][st]=0;
	heap.push((HeapElementData){0,st});
	for (int i=0;i<n;i++){
		HeapElementData now;
		while (1){
			if (heap.size()==0) break;
			now=heap.top();
			if (now.x!=dst[num][now.id]||vis[now.id]) heap.pop(); else break;
		}
		if (heap.size()<0) break;
		vis[now.id]=1;
		for (int j=lnk[now.id];j;j=nxt[j]) if (!vis[son[j]]&&now.x+w[j]<dst[num][son[j]]){
			dst[num][son[j]]=now.x+w[j];
			heap.push((HeapElementData){dst[num][son[j]],son[j]});
		}
	}
}
inline void Init(){
	memset(dst,63,sizeof(dst));
	memset(nxt,0,sizeof(nxt));
	memset(son,0,sizeof(son));
	memset(lnk,0,sizeof(lnk));
	tot=0;
}
inline int count(int x){
	int ret=0;
	while (x){
		ret+=x&1;
		x>>=1;
	}
	return ret;
}
int main(){
	t=read();int all_cnt=0;
	while (t--){
		printf("Case %d: ",++all_cnt);
		Init();
		n=read();m=read();d=read();
		for (int i=0;i<d;i++) shop[i]=read();
		for (int i=0;i<m;i++){
			int x=read(),y=read(),z=read();
			add(x,y,z);
		}
		s=1<<d;
		for (int i=0;i<d;i++) Dijkstra(i,shop[i]);
		Dijkstra(20,0);
		memset(f,63,sizeof(f));INF=f[0][0];
//		f[0][0]=0;
		for (int i=0;i<d;i++) f[1<<i][i]=dst[20][shop[i]];
//		printf("OUTPUT %d\n",f[1][0]);
//		printf("OUTPUT %d\n",dst[20][2]);
		for (int j=1;j<s;j++)
		for (int i=0;i<d;i++) if (j&(1<<i)){
			int lst_dyn=j-(1<<i);
			for (int k=0;k<d;k++) if (((lst_dyn&(1<<k)||(lst_dyn==0)))&&(f[lst_dyn][k]!=INF)&&(dst[k][shop[i]]!=INF)) f[j][i]=min(f[j][i],f[lst_dyn][k]+dst[k][shop[i]]);
		}
		int ans_num_max=0,ans_tme_min=1<<30;
		for (int j=1;j<s;j++)
		for (int i=0;i<d;i++) if ((j&(1<<i))&&(f[j][i]+dst[i][n-1]<INF)){
			int cnt=count(j);
			if (cnt>ans_num_max){
				ans_num_max=cnt;
				ans_tme_min=f[j][i]+dst[i][n-1];
//				printf("Update_0: %d, %d\n",ans_num_max,ans_tme_min);
			} else if (cnt==ans_num_max&&f[j][i]+dst[i][n-1]<ans_tme_min){
				ans_tme_min=f[j][i]+dst[i][n-1];
//				printf("Update_1: %d, %d\n",ans_num_max,ans_tme_min);
			}
		}
		if (ans_tme_min>=INF) printf("Impossible\n"); else
		printf("%d %d\n",ans_num_max,ans_tme_min);
	}
	return 0;
}
