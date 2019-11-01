#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=20,maxm=305;
const int flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int tt=1e9+7;

int n,m;
int a[maxn][maxn],e[maxn][maxn];
bool vis[maxn][maxn],now[maxn][maxn];

int ans[maxm];

void make_flag(int x,int y){
	now[x][y]=false;
	for (int i=0;i<4;i++) if (now[x+flg[i][0]][y+flg[i][1]])
		make_flag(x+flg[i][0],y+flg[i][1]);
}

bool check(){
	bool isc=false,isl=false;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			now[i][j]=vis[i][j];
			if (i==1 && now[i][j]==true) isc=true;
			if (j==1 && now[i][j]==true) isl=true;
		}
	if ((isc==false)||(isl==false)) return false;

	bool did=false;
	for (int i=1;i<=n && did==false;i++)
		for (int j=1;j<=n && did==false;j++)
			if (now[i][j]){make_flag(i,j);did=true;break;}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (now[i][j]) return false;
	return true;
}

void DFS(int x,int y,int step,int k,int b){
	if (b>m) return;
	if (step==n){
		if (check()==false) return;
		ans[b]=(ans[b]+k)%tt;
		return;
	}
	if (y>n) x++,y=1;
	if (x>n) return;

	for (int j=y+1;j<=n;j++){
		vis[x][j]=true;
		DFS(x,j,step+1,k*a[x][j]%tt,b+e[x][j]);
		vis[x][j]=false;
	}
	for (int i=x+1;i<=n;i++)
		for (int j=1;j<=n;j++){
			vis[i][j]=true;
			DFS(i,j,step+1,k*a[i][j]%tt,b+e[i][j]);
			vis[i][j]=false;
		}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read();

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=read(),e[i][j]=read();

	DFS(1,0,0,1,0);

	for (int i=0;i<=m;i++) printf("%lld ",ans[i]);
	return 0;

	return 0;
}