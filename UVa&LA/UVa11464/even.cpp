#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=20,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int T,n,aans=1<<30;
bool a[maxn][maxn],ans[maxn][maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void DFS(int i,int cnt){
	if (cnt>=aans) return;
	if (i>n){
		for (i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans[i][j]=a[i][j];
		for (i=1;i<n;i++)
		for (int j=1;j<=n;j++){
			int nowsum=0;
			for (int ii=0;ii<4;ii++) nowsum+=ans[i+flg[ii][0]][j+flg[ii][1]];
			if (nowsum&1){
				if (a[i+1][j]) return;
				ans[i+1][j]=!a[i+1][j];
				cnt++;
			}
			if (cnt>=aans) return;
		}
		for (int j=1;j<=n;j++){
			int nowsum=0;
			for (int ii=0;ii<4;ii++) nowsum+=ans[n+flg[ii][0]][j+flg[ii][1]];
			if (nowsum&1) return;
		}
		if (cnt<aans) aans=cnt;
		return;
	} else {
		DFS(i+1,cnt);
		if (a[1][i]) return;
		a[1][i]=!a[1][i];
		DFS(i+1,cnt+1);
		a[1][i]=!a[1][i];
	}
}
int main(){
	freopen("even.in","r",stdin);
	freopen("even.out","w",stdout);
	T=read();
	for (int t=1;t<=T;t++){
		memset(a,0,sizeof(a));
		n=read();aans=1<<30;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j]=read();
		DFS(2,0);if (a[1][1]==0){a[1][1]=!a[1][1];DFS(2,1);}
		if (aans==(1<<30)) printf("Case %d: -1\n",t); else printf("Case %d: %d\n",t,aans);
	}
	return 0;
}
