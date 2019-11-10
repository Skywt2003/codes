#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;
const int maxe=250005;

int n;

struct doll{int x,y,z;};
doll a[maxn];

bool inc(doll aa,doll bb){
	return aa.x<bb.x && aa.y<bb.y && aa.z<bb.z;
}

int tot=0,lnk[maxn],nxt[maxe],to[maxe];

void graph_init(){
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
}

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

int con_x[maxn],con_y[maxn],vis[maxn];

bool DFS(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]]){
		vis[to[i]]=true;
		if (con_y[to[i]]==-1 || DFS(con_y[to[i]])){
			con_x[x]=to[i];
			con_y[to[i]]=x;
			return true;
		}
	}
	return false;
}

int max_match(){
	memset(con_x,-1,sizeof(con_x));
	memset(con_y,-1,sizeof(con_y));
	int ret=0;
	for (int i=1;i<=2*n;i++){
		memset(vis,0,sizeof(vis));
		ret+=DFS(i);
	}
	return ret;
}

bool compare_x(doll aa,doll bb){
	return aa.x < bb.x;
}

signed main(){
	n=read();
	while (n){
		graph_init();
		for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
		sort(a+1,a+1+n,compare_x);
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (inc(a[i],a[j])) add_edge(i,j+n);
		for (int i=1;i<=n;i++) add_edge(n+i,i);
		printf("%d\n",2*n-max_match());
		n=read();
	}
	return 0;
}