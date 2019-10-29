#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;

const int maxn=105;
const int flg[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int n,m,w,k;

int a[maxn][maxn];
int inv,ans=0,ans2=0;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

bool check(int x,int y){
	if (x<1||y<1||x>n||y>m) return false;
	return true;
}

void DFS(int x,int y,int now){
	if (now==0){
		int sum=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) if (!a[i][j])
				for (int k=0;k<8;k++) if (check(i+flg[k][0],j+flg[k][1]))
					sum=(sum+a[i+flg[k][0]][j+flg[k][1]])%tt;

		ans=(ans+sum)%tt;
		return;
	}
	if (y>m) x++,y=1;
	if (x>n) return;
	for (int j=y+1;j<=m;j++) if (!a[x][j]){
		a[x][j]=true;
		DFS(x,j+1,now-1);
		a[x][j]=false;
	}
	for (int i=x+1;i<=n;i++){
		for (int j=1;j<=m;j++) if (!a[i][j]){
			a[i][j]=true;
			DFS(i,j+1,now-1);
			a[i][j]=false;
		}
	}
}

void DFS2(int x,int y,int now){
	if (now==0){
		int sum=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) if (!a[i][j])
				for (int k=0;k<8;k++) if (check(i+flg[k][0],j+flg[k][1]))
					sum=(sum+a[i+flg[k][0]][j+flg[k][1]])%tt;

		ans2=(ans2+ ((sum-ans)%tt+tt)%tt * ((sum-ans)%tt+tt)%tt )%tt;
		return;
	}
	if (y>m) x++,y=1;
	if (x>n) return;
	for (int j=y+1;j<=m;j++) if (!a[x][j]){
		a[x][j]=true;
		DFS2(x,j+1,now-1);
		a[x][j]=false;
	}
	for (int i=x+1;i<=n;i++){
		for (int j=1;j<=m;j++) if (!a[i][j]){
			a[i][j]=true;
			DFS2(i,j+1,now-1);
			a[i][j]=false;
		}
	}
}

int fac(int x){
	int ret=1;
	for (int i=2;i<=x;i++) ret=ret*i%tt;
	return ret;
}

int C(int n,int m){
	if (n<m) return 0;
	return fac(n)*qsm(fac(m),tt-2)%tt*qsm(fac(n-m),tt-2)%tt;
}

signed main(){
	// freopen("mine.in","r",stdin);
	// freopen("mine.out","w",stdout);

	n=read();m=read();w=read();k=read();
	for (int i=1;i<=k;i++){
		int x=read(),y=read();
		a[x][y]=true;
	}

	int tot=C(n*m-k,w-k);
	inv=qsm(tot,tt-2);

	DFS(1,0,w-k);
	ans=ans*inv%tt;

	DFS2(1,0,w-k);
	ans2=ans2*inv%tt;

	printf("%lld %lld\n",ans,ans2);
	return 0;
}