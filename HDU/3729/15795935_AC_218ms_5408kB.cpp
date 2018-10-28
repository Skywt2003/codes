#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define CLEAR(_) memset(_,0,sizeof(_))
#define CLEAR_REG(_) memset(_,-1,sizeof(_))
#define CLEAR_MAX(_) memset(_,0x3f,sizeof(_))
#define CLAER_MIN(_) memset(_,0x80,sizeof(_))

const int maxn=100005+60,maxe=6000005;
int T,n,m,vis[maxn],con_x[maxn],con_y[maxn],ans[maxn];
vector <int> lnk[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void init(){
	CLEAR_REG(con_x);CLEAR_REG(con_y);
	CLEAR(ans);
	for (int i=1;i<=n;i++) lnk[i].clear();
}
inline void add(int x,int y){
	lnk[x].push_back(y);
}
inline bool DFS(int s){
	for (int i=0;i<lnk[s].size();i++) if (!vis[lnk[s][i]]){
		int t=lnk[s][i];vis[t]=true;
		if ((con_y[t]==-1)||(DFS(con_y[t]))){
			con_x[s]=t;
			con_y[t]=s;
			return true;
		}
	}
	return false;
}
inline int max_match(){
	int ret=0;
	for (int i=n;i>=1;i--){
		CLEAR(vis);
		if (DFS(i)) ret++,ans[i]=true;
	}
	return ret;
}
int main(){
	T=read();
	while (T--){
		n=read();
		init();
		for (int i=1;i<=n;i++){
			int x=read(),y=read();
			for (int j=x;j<=y;j++) add(i,j+n),add(j+n,i);
		}
		int now=max_match();
		printf("%d\n",now);
		vector<int> prt;prt.clear();
		for (int i=1;i<=n;i++) if (ans[i]) prt.push_back(i);
		for (int i=0;i<prt.size();i++) printf(i==prt.size()-1?"%d\n":"%d ",prt[i]);
	}
	return 0;
}